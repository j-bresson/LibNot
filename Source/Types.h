//
//  Types.h
//  LibNot
//
//  Created by Jean Bresson on 13/02/2019.
//

#ifndef Types_h
#define Types_h

typedef void (*lnCloseCallback)( void * win);
typedef void (*lnUpdateCallback)( void * win, int n );


typedef enum {G,F,GF,GG,FF,GGF,GFF,GGFF,LINE,EMPTY} staff_t;

#endif  /* Types_h */
