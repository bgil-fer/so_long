cc main.c -Lminilibx-linux -lmlx_Linux -lX11 -lXext
-lm para la libreria math

Masks de MINILIBX:
- NoEventMask (0L): No se captura ningún evento.
- KeyPressMask ((1L<<0)): Captura eventos de pulsación de teclas.
- KeyReleaseMask ((1L<<1)): Captura eventos de liberación de teclas.
- ButtonPressMask ((1L<<2)): Captura eventos de pulsación de botones del ratón.
- ButtonReleaseMask ((1L<<3)): Captura eventos de liberación de botones del ratón.
- EnterWindowMask ((1L<<4)): Captura eventos de entrada del cursor a la ventana.
- LeaveWindowMask ((1L<<5)): Captura eventos de salida del cursor de la ventana.
- PointerMotionMask ((1L<<6)): Captura eventos de movimiento del puntero.
- PointerMotionHintMask ((1L<<7)): Captura eventos de movimiento del puntero con sugerencias.
- Button1MotionMask ((1L<<8)): Captura eventos de movimiento del puntero mientras se mantiene presionado el botón 1.
- Button2MotionMask ((1L<<9)): Captura eventos de movimiento del puntero mientras se mantiene presionado el botón 2.
- Button3MotionMask ((1L<<10)): Captura eventos de movimiento del puntero mientras se mantiene presionado el botón 3.
- Button4MotionMask ((1L<<11)): Captura eventos de movimiento del puntero mientras se mantiene presionado el botón 4.
- Button5MotionMask ((1L<<12)): Captura eventos de movimiento del puntero mientras se mantiene presionado el botón 5.
- ButtonMotionMask ((1L<<13)): Captura eventos de movimiento del puntero mientras se mantiene presionado cualquier botón del ratón.
- KeymapStateMask ((1L<<14)): Captura cambios en el estado del mapa de teclas.
- ExposureMask ((1L<<15)): Captura eventos de exposición de la ventana (cuando una parte de la ventana se vuelve visible).
- VisibilityChangeMask ((1L<<16)): Captura cambios en la visibilidad de la ventana.
- StructureNotifyMask ((1L<<17)): Captura eventos relacionados con cambios en la estructura de la ventana (por ejemplo, redimensionamiento, movimiento).
- ResizeRedirectMask ((1L<<18)): Captura eventos de redireccionamiento de redimensionamiento de la ventana.
- SubstructureNotifyMask ((1L<<19)): Captura eventos de cambios en la subestructura de la ventana.
- SubstructureRedirectMask ((1L<<20)): Captura eventos de redireccionamiento de la subestructura de la ventana.
- FocusChangeMask ((1L<<21)): Captura eventos de cambio de foco.
- PropertyChangeMask ((1L<<22)): Captura eventos de cambio de propiedades de la ventana.
- ColormapChangeMask ((1L<<23)): Captura eventos de cambio de mapa de colores.
- OwnerGrabButtonMask ((1L<<24)): Captura eventos de captura de botones por el propietario.


https://github.com/josephcheel/42-So_long/blob/master/Mandatory/src/check_valid_path.c -> Floodfill


#ifndef LINUX_KEYS_H
# define LINUX_KEYS_H

/*
** Keyboard alphabet
*/

# define K_A 97
# define K_B 98
# define K_C 99
# define K_D 100
# define K_E 101
# define K_F 102
# define K_G 103
# define K_H 104
# define K_I 105
# define K_J 106
# define K_K 107
# define K_L 108
# define K_M 109
# define K_N 110
# define K_O 111
# define K_P 112
# define K_Q 113
# define K_R 114
# define K_S 115
# define K_T 116
# define K_U 117
# define K_V 118
# define K_W 119
# define K_X 120
# define K_Y 121
# define K_Z 122

/*
** Keyboard arrows
*/

# define K_AR_L 65361
# define K_AR_U 65362
# define K_AR_R 65363
# define K_AR_D 65364

/*
** Keyboard upper row symbols & punctuation/numbers
*/

# define K_TILDE 96
# define K_EXCL 49
# define K_AT 40
# define K_SHARP 51
# define K_DOLLAR 52
# define K_PCENT 53
# define K_CARET 54
# define K_ET 55
# define K_STAR 56
# define K_O_PARENTH 57
# define K_C_PARENTH 48
# define K_DASH 45
# define K_PLUS 61

/*
** Keyboard other punctutation
*/

# define K_SPACE 32
# define K_O_BRACK 91
# define K_C_BRACK 93
# define K_PIPE 92
# define K_SCOLON 59
# define K_QUOTE 39
# define K_COMMA 44
# define K_DOT 46
# define K_SLASH 47

/*
** Keyboard misc.
*/

# define K_ESC 65307
# define K_TAB 65289
# define K_CAPS 65509
# define K_SHIFT_L 65505
# define K_SHIFT_R 65506
# define K_CTRL_L 65507
# define K_CTRL_R 65508
# define K_ALT_L 65513
# define K_ALT_R 65212
# define K_CMD_R 65516
# define K_DEL 65288
# define K_RETURN 65293

/*
** Keyboard function keys
*/

# define K_HOME 65360
# define K_PG_UP 65365
# define K_PG_DN 65366

/*
** Keyboard numeric pad
*/

# define K_NP_CLEAR 65407
# define K_NP_EQUAL 65469
# define K_NP_DOT 65439
# define K_NP_ENTER 65421
# define K_NP_DIV 65455
# define K_NP_MUL 65450
# define K_NP_MIN 65453
# define K_NP_PLU 65451
# define K_NP_0 65438
# define K_NP_1 65436
# define K_NP_2 65433
# define K_NP_3 65435
# define K_NP_4 65430
# define K_NP_5 65437
# define K_NP_6 65432
# define K_NP_7 65429
# define K_NP_8 65431
# define K_NP_9 65434

/*
** Mouse
*/

# define M_CLK_L 1
# define M_CLK_M 2
# define M_CLK_R 3
# define M_SCR_U 4
# define M_SCR_D 5

/*
These are not defined yet

** Keyboard MISC :
# define K_CMD_L


** Keyboard function keys :
# define K_F1
# define K_F2
# define K_F3
# define K_F4 
# define K_F5
# define K_F6
# define K_F7
# define K_F8
# define K_F9
# define K_F10
# define K_F11
# define K_F12
# define K_F13
# define K_F14
# define K_F15
# define K_F_KEY
# define K_END 
# define K_FN_DEL
# define K_REMOVE 

*/

#endif
