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


(in-package :cl-user)

(defpackage :libnot
  (:use :common-lisp :cl-user))

(defvar libnot::libnot nil)

(defun load-libnot-lib ()
  (setf libnot::libnot
        (om-fi::om-load-foreign-library 
         "LibNot"
         `(;; (:macosx ,(om-fi::om-foreign-library-pathname "libLibNot.dylib"))
           (:macosx ,(merge-pathnames "lib/mac/libLibNot.dylib" (om::mypathname (om::find-library "libnot"))))
           (t (:default "LibNot"))))))

(push :libnot *features*)

;; load now
(load-libnot-lib)

;; load at OM startup
;; #+macosx(om-fi::add-foreign-loader 'load-libnot-lib)


(in-package :libnot)

(cffi::defcfun ("libNotInfo" libNotInfo) :string)
(cffi::defcfun ("libNotNewEditor" libNotNewEditor) :pointer)
(cffi::defcfun ("libNotFreeEditor" libNotFreeEditor) :void (libNot_editor :pointer))
(cffi::defcfun ("libNotOpenWindow" libNotOpenWindow) :void (libNot_editor :pointer))
(cffi::defcfun ("libNotCloseWindow" libNotCloseWindow) :void (libNot_editor :pointer))
(cffi::defcfun ("libNotWindowToFront" libNotWindowToFront) :void (libNot_editor :pointer))
(cffi::defcfun ("libNotWindowSetName" libNotWindowSetName) :void (libNot_editor :pointer) (name :string))

;; (libnot::libNotInfo)
;; (libnot::libnotopenwindow (libnot::libnotneweditor))



;;; CALLBACKS
(cffi:defcfun ("libNotRegisterCloseCallback" libNotRegisterCloseCallback) :void (libNot_editor :pointer) (callback :pointer))
(cffi:defcfun ("libNotRegisterUpdateCallback" libNotRegisterUpdateCallback) :void (libNot_editor :pointer) (callback :pointer))

(cffi::defcallback ln-close-callback :void ((libNot_editor :pointer))
  (handler-bind ((error #'(lambda (e) (print (format nil "ERROR IN LN CLOSE CALLBACK: ~% ~A" e)))))
    (handle-ln-close-callback libNot_editor)))

(cffi::defcallback ln-update-callback :void ((libNot_editor :pointer) (n :int))
  (handler-bind ((error #'(lambda (e) (print (format nil "ERROR IN LN UPDATE CALLBACK: ~% ~A" e)))))
    (handle-ln-update-callback libNot_editor n)))

;;; FUNCTION TO CALL FROM OM
(defun libNotRegisterCallbacks (libNot_editor)
  (libNotRegisterCloseCallback libNot_editor (cffi::get-callback 'ln-close-callback))
  (libnotRegisterUpdateCallback libNot_editor (cffi::get-callback 'ln-update-callback)))

;;; to be redefined
(defun handle-ln-close-callback (libNot_editor) 
  (declare (ignore libNot_editor))
  (print "libnot close callback undefined"))

;;; to be redefined
(defun handle-ln-update-callback (libNot_editor n) 
  (declare (ignore libNot_editor n))
  (print "libnot update callback undefined"))
