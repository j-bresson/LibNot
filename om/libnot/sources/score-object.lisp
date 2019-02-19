;============================================================================
; om7: visual programming language for computer-aided music composition
; Copyright (c) 2013-2017 J. Bresson et al., IRCAM.
; - based on OpenMusic (c) IRCAM 1997-2017 by G. Assayag, C. Agon, J. Bresson
;============================================================================
;
;   This program is free software. For information on usage 
;   and redistribution, see the "LICENSE" file in this distribution.
;
;   This program is distributed in the hope that it will be useful,
;   but WITHOUT ANY WARRANTY; without even the implied warranty of
;   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. 
;
;============================================================================
; File author: J. Bresson
;============================================================================

(in-package :om)



(defmethod object-has-editor ((self voice)) t)
(defmethod get-editor-class ((self voice)) 'libnot-editor)

(defclass libnot-editor (OMEditor play-editor-mixin) 
  ((ln-handler :accessor ln-handler :initform nil)))

(defvar *libnot-editors* nil)

(defun close-all-libnot-editors ()
  #'(lambda () (mapc '#(lambda (ed) (editor-close ed) sleep 1) *libnot-editors*)))

(add-om-exit-action 'close-all-libnot-editors)


(defmethod open-editor-window ((self libnot-editor))
  (if (ln-handler self)
      (libnot::libNotWindowToFront (ln-handler self))
    (let* ((ln-editor (libnot::libnotneweditor)))
      
      (om-print (libnot::libNotInfo))
      (libnot::libnotopenwindow ln-editor)
      
      (setf (ln-handler self) ln-editor)
      (push self *libnot-editors*)
      ;; (libnot::libnotWindowSetName ln-editor (editor-window-title self))
      
      (libnot::libnotRegisterCallbacks ln-editor) 
  
      nil)))
  

;;; When the close action comes from OM:
(defmethod editor-close ((self libnot-editor))
  (when (ln-handler self)
    (libnot::libnotclosewindow (ln-handler self))
    (libnot::libnotfreeeditor (ln-handler self))
    (setf (ln-handler self) nil))
  (setf *libnot-editors* (remove self *libnot-editors*))
  (call-next-method))

;;; When the close action comes from the editor:
(defun libnot::handle-ln-close-callback (ln-editor)
  
  (let ((ed (find ln-editor *libnot-editors* :key 'ln-handler :test 'om-pointer-equal)))
    (if ed
        (let ()
          (libnot::libnotfreeeditor (ln-handler ed))
          (setf (ln-handler ed) nil)
          (setf *libnot-editors* (remove ed *libnot-editors*)))
      (om-print "window-close callback : editor not found" "LIBNOT")
      )))


#|
(defmethod update-to-editor ((self sym-editor) (from t)) 
  (when (symbolist-handler self)
    (let ((ptr (symbolist-make-score-pointer (object-value self))))
      (symbolist::symbolistWindowSetName (symbolist-handler self) (editor-window-title self))
      (symbolist::symbolistSetSymbols (symbolist-handler self) (length (symbols (object-value self))) ptr)
      t
      )))
|#

