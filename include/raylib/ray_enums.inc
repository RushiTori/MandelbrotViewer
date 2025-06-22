%ifndef RAY_ENUMS_INC
%define RAY_ENUMS_INC

%include "types_utils.inc"

; System/Window config flags
; NOTE: Every bit registers one state (use it with bit masks)
; By default all flags are set to 0
; enum ConfigFlags

	; Set to try enabling V-Sync on GPU
	add_enum_value(FLAG_VSYNC_HINT, 0x00000040)

	; Set to run program in fullscreen
	add_enum_value(FLAG_FULLSCREEN_MODE, 0x00000002)

	; Set to allow resizable window
	add_enum_value(FLAG_WINDOW_RESIZABLE, 0x00000004)

	; Set to disable window decoration (frame and buttons)
	add_enum_value(FLAG_WINDOW_UNDECORATED, 0x00000008)

	; Set to hide window
	add_enum_value(FLAG_WINDOW_HIDDEN, 0x00000080)

	; Set to minimize window (iconify)
	add_enum_value(FLAG_WINDOW_MINIMIZED, 0x00000200)

	; Set to maximize window (expanded to monitor)
	add_enum_value(FLAG_WINDOW_MAXIMIZED, 0x00000400)

	; Set to window non focused
	add_enum_value(FLAG_WINDOW_UNFOCUSED, 0x00000800)

	; Set to window always on top
	add_enum_value(FLAG_WINDOW_TOPMOST, 0x00001000)

	; Set to allow windows running while minimized
	add_enum_value(FLAG_WINDOW_ALWAYS_RUN, 0x00000100)

	; Set to allow transparent framebuffer
	add_enum_value(FLAG_WINDOW_TRANSPARENT, 0x00000010)

	; Set to support HighDPI
	add_enum_value(FLAG_WINDOW_HIGHDPI, 0x00002000)

	; Set to support mouse passthrough, only supported when FLAG_WINDOW_UNDECORATED
	add_enum_value(FLAG_WINDOW_MOUSE_PASSTHROUGH, 0x00004000)

	; Set to run program in borderless windowed mode
	add_enum_value(FLAG_BORDERLESS_WINDOWED_MODE, 0x00008000)

	; Set to try enabling MSAA 4X
	add_enum_value(FLAG_MSAA_4X_HINT, 0x00000020)

	; Set to try enabling interlaced video format (for V3D)
	add_enum_value(FLAG_INTERLACED_HINT, 0x00010000)

; Trace log level
; NOTE: Organized by priority level
; enum TraceLogLevel

	reset_enum_value(0)

	; Display all logs
	add_enum(LOG_ALL)

	; Trace logging, intended for internal use only
	add_enum(LOG_TRACE)

	; Debug logging, used for internal debugging, it should be disabled on release builds
	add_enum(LOG_DEBUG)

	; Info logging, used for program execution info
	add_enum(LOG_INFO)

	; Warning logging, used on recoverable failures
	add_enum(LOG_WARNING)

	; Error logging, used on unrecoverable failures
	add_enum(LOG_ERROR)

	; Fatal logging, used to abort program: exit(EXIT_FAILURE)
	add_enum(LOG_FATAL)

	; Disable logging
	add_enum(LOG_NONE)

; Keyboard keys (US keyboard layout)
; NOTE: Use GetKeyPressed() to allow redefining
; required keys for alternative layouts
; enum KeyboardKey

	; Key: NULL, used for no key pressed
	add_enum_value(KEY_NULL, 0)

	; Alphanumeric keys

		; Key: '
		add_enum_value(KEY_APOSTROPHE, 39)

		; Key: ,
		add_enum_value(KEY_COMMA, 44)

		; Key: -
		add_enum_value(KEY_MINUS, 45)

		; Key: .
		add_enum_value(KEY_PERIOD, 46)

		; Key: /
		add_enum_value(KEY_SLASH, 47)

		; Key: 0
		add_enum_value(KEY_ZERO, 48)

		; Key: 1
		add_enum_value(KEY_ONE, 49)

		; Key: 2
		add_enum_value(KEY_TWO, 50)

		; Key: 3
		add_enum_value(KEY_THREE, 51)

		; Key: 4
		add_enum_value(KEY_FOUR, 52)

		; Key: 5
		add_enum_value(KEY_FIVE, 53)

		; Key: 6
		add_enum_value(KEY_SIX, 54)

		; Key: 7
		add_enum_value(KEY_SEVEN, 55)

		; Key: 8
		add_enum_value(KEY_EIGHT, 56)

		; Key: 9
		add_enum_value(KEY_NINE, 57)

		; Key: ;
		add_enum_value(KEY_SEMICOLON, 59)

		; Key: =
		add_enum_value(KEY_EQUAL, 61)

		; Key: A | a
		add_enum_value(KEY_A, 65)

		; Key: B | b
		add_enum_value(KEY_B, 66)

		; Key: C | c
		add_enum_value(KEY_C, 67)

		; Key: D | d
		add_enum_value(KEY_D, 68)

		; Key: E | e
		add_enum_value(KEY_E, 69)

		; Key: F | f
		add_enum_value(KEY_F, 70)

		; Key: G | g
		add_enum_value(KEY_G, 71)

		; Key: H | h
		add_enum_value(KEY_H, 72)

		; Key: I | i
		add_enum_value(KEY_I, 73)

		; Key: J | j
		add_enum_value(KEY_J, 74)

		; Key: K | k
		add_enum_value(KEY_K, 75)

		; Key: L | l
		add_enum_value(KEY_L, 76)

		; Key: M | m
		add_enum_value(KEY_M, 77)

		; Key: N | n
		add_enum_value(KEY_N, 78)

		; Key: O | o
		add_enum_value(KEY_O, 79)

		; Key: P | p
		add_enum_value(KEY_P, 80)

		; Key: Q | q
		add_enum_value(KEY_Q, 81)

		; Key: R | r
		add_enum_value(KEY_R, 82)

		; Key: S | s
		add_enum_value(KEY_S, 83)

		; Key: T | t
		add_enum_value(KEY_T, 84)

		; Key: U | u
		add_enum_value(KEY_U, 85)

		; Key: V | v
		add_enum_value(KEY_V, 86)

		; Key: W | w
		add_enum_value(KEY_W, 87)

		; Key: X | x
		add_enum_value(KEY_X, 88)

		; Key: Y | y
		add_enum_value(KEY_Y, 89)

		; Key: Z | z
		add_enum_value(KEY_Z, 90)

		; Key: [
		add_enum_value(KEY_LEFT_BRACKET, 91)

		; Key: '\'
		add_enum_value(KEY_BACKSLASH, 92)

		; Key: ]
		add_enum_value(KEY_RIGHT_BRACKET, 93)

		; Key: `
		add_enum_value(KEY_GRAVE, 96)

	; Function keys

		; Key: Space
		add_enum_value(KEY_SPACE, 32)

		; Key: Esc
		add_enum_value(KEY_ESCAPE, 256)

		; Key: Enter
		add_enum_value(KEY_ENTER, 257)

		; Key: Tab
		add_enum_value(KEY_TAB, 258)

		; Key: Backspace
		add_enum_value(KEY_BACKSPACE, 259)

		; Key: Ins
		add_enum_value(KEY_INSERT, 260)

		; Key: Del
		add_enum_value(KEY_DELETE, 261)

		; Key: Cursor right
		add_enum_value(KEY_RIGHT, 262)

		; Key: Cursor left
		add_enum_value(KEY_LEFT, 263)

		; Key: Cursor down
		add_enum_value(KEY_DOWN, 264)

		; Key: Cursor up
		add_enum_value(KEY_UP, 265)

		; Key: Page up
		add_enum_value(KEY_PAGE_UP, 266)

		; Key: Page down
		add_enum_value(KEY_PAGE_DOWN, 267)

		; Key: Home
		add_enum_value(KEY_HOME, 268)

		; Key: End
		add_enum_value(KEY_END, 269)

		; Key: Caps lock
		add_enum_value(KEY_CAPS_LOCK, 280)

		; Key: Scroll down
		add_enum_value(KEY_SCROLL_LOCK, 281)

		; Key: Num lock
		add_enum_value(KEY_NUM_LOCK, 282)

		; Key: Print screen
		add_enum_value(KEY_PRINT_SCREEN, 283)

		; Key: Pause
		add_enum_value(KEY_PAUSE, 284)

		; Key: F1
		add_enum_value(KEY_F1, 290)

		; Key: F2
		add_enum_value(KEY_F2, 291)

		; Key: F3
		add_enum_value(KEY_F3, 292)

		; Key: F4
		add_enum_value(KEY_F4, 293)

		; Key: F5
		add_enum_value(KEY_F5, 294)

		; Key: F6
		add_enum_value(KEY_F6, 295)

		; Key: F7
		add_enum_value(KEY_F7, 296)

		; Key: F8
		add_enum_value(KEY_F8, 297)

		; Key: F9
		add_enum_value(KEY_F9, 298)

		; Key: F10
		add_enum_value(KEY_F10, 299)

		; Key: F11
		add_enum_value(KEY_F11, 300)

		; Key: F12
		add_enum_value(KEY_F12, 301)

		; Key: Shift left
		add_enum_value(KEY_LEFT_SHIFT, 340)

		; Key: Control left
		add_enum_value(KEY_LEFT_CONTROL, 341)

		; Key: Alt left
		add_enum_value(KEY_LEFT_ALT, 342)

		; Key: Super left
		add_enum_value(KEY_LEFT_SUPER, 343)

		; Key: Shift right
		add_enum_value(KEY_RIGHT_SHIFT, 344)

		; Key: Control right
		add_enum_value(KEY_RIGHT_CONTROL, 345)

		; Key: Alt right
		add_enum_value(KEY_RIGHT_ALT, 346)

		; Key: Super right
		add_enum_value(KEY_RIGHT_SUPER, 347)

		; Key: KB menu
		add_enum_value(KEY_KB_MENU, 348)

	; Keypad keys

		; Key: Keypad 0
		add_enum_value(KEY_KP_0, 320)

		; Key: Keypad 1
		add_enum_value(KEY_KP_1, 321)

		; Key: Keypad 2
		add_enum_value(KEY_KP_2, 322)

		; Key: Keypad 3
		add_enum_value(KEY_KP_3, 323)

		; Key: Keypad 4
		add_enum_value(KEY_KP_4, 324)

		; Key: Keypad 5
		add_enum_value(KEY_KP_5, 325)

		; Key: Keypad 6
		add_enum_value(KEY_KP_6, 326)

		; Key: Keypad 7
		add_enum_value(KEY_KP_7, 327)

		; Key: Keypad 8
		add_enum_value(KEY_KP_8, 328)

		; Key: Keypad 9
		add_enum_value(KEY_KP_9, 329)

		; Key: Keypad .
		add_enum_value(KEY_KP_DECIMAL, 330)

		; Key: Keypad /
		add_enum_value(KEY_KP_DIVIDE, 331)

		; Key: Keypad *
		add_enum_value(KEY_KP_MULTIPLY, 332)

		; Key: Keypad -
		add_enum_value(KEY_KP_SUBTRACT, 333)

		; Key: Keypad +
		add_enum_value(KEY_KP_ADD, 334)

		; Key: Keypad Enter
		add_enum_value(KEY_KP_ENTER, 335)

		; Key: Keypad =
		add_enum_value(KEY_KP_EQUAL, 336)

	; Android key buttons

		; Key: Android back button
		add_enum_value(KEY_BACK, 4)

		; Key: Android menu button
		add_enum_value(KEY_MENU, 5)

		; Key: Android volume up button
		add_enum_value(KEY_VOLUME_UP, 24)

		; Key: Android volume down button
		add_enum_value(KEY_VOLUME_DOWN, 25)

; Mouse buttons
; enum MouseButton

	reset_enum_value(0)

	; Mouse button left
	add_enum(MOUSE_BUTTON_LEFT)

	; Mouse button right
	add_enum(MOUSE_BUTTON_RIGHT)

	; Mouse button middle (pressed wheel)
	add_enum(MOUSE_BUTTON_MIDDLE)

	; Mouse button side (advanced mouse device)
	add_enum(MOUSE_BUTTON_SIDE)

	; Mouse button extra (advanced mouse device)
	add_enum(MOUSE_BUTTON_EXTRA)

	; Mouse button forward (advanced mouse device)
	add_enum(MOUSE_BUTTON_FORWARD)

	; Mouse button back (advanced mouse device)
	add_enum(MOUSE_BUTTON_BACK)

; Mouse cursor
; enum MouseCursor

	reset_enum_value(0)

	; Default pointer shape
	add_enum(MOUSE_CURSOR_DEFAULT)

	; Arrow shape
	add_enum(MOUSE_CURSOR_ARROW)

	; Text writing cursor shape
	add_enum(MOUSE_CURSOR_IBEAM)

	; Cross shape
	add_enum(MOUSE_CURSOR_CROSSHAIR)

	; Pointing hand cursor
	add_enum(MOUSE_CURSOR_POINTING_HAND)

	; Horizontal resize/move arrow shape
	add_enum(MOUSE_CURSOR_RESIZE_EW)

	; Vertical resize/move arrow shape
	add_enum(MOUSE_CURSOR_RESIZE_NS)

	; Top-left to bottom-right diagonal resize/move arrow shape
	add_enum(MOUSE_CURSOR_RESIZE_NWSE)

	; The top-right to bottom-left diagonal resize/move arrow shape
	add_enum(MOUSE_CURSOR_RESIZE_NESW)

	; The omnidirectional resize/move cursor shape
	add_enum(MOUSE_CURSOR_RESIZE_ALL)

	; The operation-not-allowed shape
	add_enum(MOUSE_CURSOR_NOT_ALLOWED)

; Gamepad buttons
; enum GamepadButton

	reset_enum_value(0)

	; Unknown button, just for error checking
	add_enum(GAMEPAD_BUTTON_UNKNOWN)

	; Gamepad left DPAD up button
	add_enum(GAMEPAD_BUTTON_LEFT_FACE_UP)

	; Gamepad left DPAD right button
	add_enum(GAMEPAD_BUTTON_LEFT_FACE_RIGHT)

	; Gamepad left DPAD down button
	add_enum(GAMEPAD_BUTTON_LEFT_FACE_DOWN)

	; Gamepad left DPAD left button
	add_enum(GAMEPAD_BUTTON_LEFT_FACE_LEFT)

	; Gamepad right button up (i.e. PS3: Triangle, Xbox: Y)
	add_enum(GAMEPAD_BUTTON_RIGHT_FACE_UP)

	; Gamepad right button right (i.e. PS3: Circle, Xbox: B)
	add_enum(GAMEPAD_BUTTON_RIGHT_FACE_RIGHT)

	; Gamepad right button down (i.e. PS3: Cross, Xbox: A)
	add_enum(GAMEPAD_BUTTON_RIGHT_FACE_DOWN)

	; Gamepad right button left (i.e. PS3: Square, Xbox: X)
	add_enum(GAMEPAD_BUTTON_RIGHT_FACE_LEFT)

	; Gamepad top/back trigger left (first), it could be a trailing button
	add_enum(GAMEPAD_BUTTON_LEFT_TRIGGER_1)

	; Gamepad top/back trigger left (second), it could be a trailing button
	add_enum(GAMEPAD_BUTTON_LEFT_TRIGGER_2)

	; Gamepad top/back trigger right (first), it could be a trailing button
	add_enum(GAMEPAD_BUTTON_RIGHT_TRIGGER_1)

	; Gamepad top/back trigger right (second), it could be a trailing button
	add_enum(GAMEPAD_BUTTON_RIGHT_TRIGGER_2)

	; Gamepad center buttons, left one (i.e. PS3: Select)
	add_enum(GAMEPAD_BUTTON_MIDDLE_LEFT)

	; Gamepad center buttons, middle one (i.e. PS3: PS, Xbox: XBOX)
	add_enum(GAMEPAD_BUTTON_MIDDLE)

	; Gamepad center buttons, right one (i.e. PS3: Start)
	add_enum(GAMEPAD_BUTTON_MIDDLE_RIGHT)

	; Gamepad joystick pressed button left
	add_enum(GAMEPAD_BUTTON_LEFT_THUMB)

	; Gamepad joystick pressed button right
	add_enum(GAMEPAD_BUTTON_RIGHT_THUMB)

; Gamepad axes
; enum GamepadAxis

	reset_enum_value(0)

	; Gamepad left stick X axis
	add_enum(GAMEPAD_AXIS_LEFT_X)

	; Gamepad left stick Y axis
	add_enum(GAMEPAD_AXIS_LEFT_Y)

	; Gamepad right stick X axis
	add_enum(GAMEPAD_AXIS_RIGHT_X)

	; Gamepad right stick Y axis
	add_enum(GAMEPAD_AXIS_RIGHT_Y)

	; Gamepad back trigger left, pressure level: [1..-1]
	add_enum(GAMEPAD_AXIS_LEFT_TRIGGER)

	; Gamepad back trigger right, pressure level: [1..-1]
	add_enum(GAMEPAD_AXIS_RIGHT_TRIGGER)

; Material map index
; enum MaterialMapIndex

	reset_enum_value(0)

	; Albedo material (same as: MATERIAL_MAP_DIFFUSE)
	add_enum(MATERIAL_MAP_ALBEDO)

	; Metalness material (same as: MATERIAL_MAP_SPECULAR)
	add_enum(MATERIAL_MAP_METALNESS)

	; Normal material
	add_enum(MATERIAL_MAP_NORMAL)

	; Roughness material
	add_enum(MATERIAL_MAP_ROUGHNESS)

	; Ambient occlusion material
	add_enum(MATERIAL_MAP_OCCLUSION)

	; Emission material
	add_enum(MATERIAL_MAP_EMISSION)

	; Heightmap material
	add_enum(MATERIAL_MAP_HEIGHT)

	; Cubemap material (NOTE: Uses GL_TEXTURE_CUBE_MAP)
	add_enum(MATERIAL_MAP_CUBEMAP)

	; Irradiance material (NOTE: Uses GL_TEXTURE_CUBE_MAP)
	add_enum(MATERIAL_MAP_IRRADIANCE)

	; Prefilter material (NOTE: Uses GL_TEXTURE_CUBE_MAP)
	add_enum(MATERIAL_MAP_PREFILTER)

	; Brdf material
	add_enum(MATERIAL_MAP_BRDF)

; Shader location index
; enum ShaderLocationIndex

	reset_enum_value(0)

	; Shader location: vertex attribute: position
	add_enum(SHADER_LOC_VERTEX_POSITION)

	; Shader location: vertex attribute: texcoord01
	add_enum(SHADER_LOC_VERTEX_TEXCOORD01)

	; Shader location: vertex attribute: texcoord02
	add_enum(SHADER_LOC_VERTEX_TEXCOORD02)

	; Shader location: vertex attribute: normal
	add_enum(SHADER_LOC_VERTEX_NORMAL)

	; Shader location: vertex attribute: tangent
	add_enum(SHADER_LOC_VERTEX_TANGENT)

	; Shader location: vertex attribute: color
	add_enum(SHADER_LOC_VERTEX_COLOR)

	; Shader location: matrix uniform: model-view-projection
	add_enum(SHADER_LOC_MATRIX_MVP)

	; Shader location: matrix uniform: view (camera transform)
	add_enum(SHADER_LOC_MATRIX_VIEW)

	; Shader location: matrix uniform: projection
	add_enum(SHADER_LOC_MATRIX_PROJECTION)

	; Shader location: matrix uniform: model (transform)
	add_enum(SHADER_LOC_MATRIX_MODEL)

	; Shader location: matrix uniform: normal
	add_enum(SHADER_LOC_MATRIX_NORMAL)

	; Shader location: vector uniform: view
	add_enum(SHADER_LOC_VECTOR_VIEW)

	; Shader location: vector uniform: diffuse color
	add_enum(SHADER_LOC_COLOR_DIFFUSE)

	; Shader location: vector uniform: specular color
	add_enum(SHADER_LOC_COLOR_SPECULAR)

	; Shader location: vector uniform: ambient color
	add_enum(SHADER_LOC_COLOR_AMBIENT)

	; Shader location: sampler2d texture: albedo (same as: SHADER_LOC_MAP_DIFFUSE)
	add_enum(SHADER_LOC_MAP_ALBEDO)

	; Shader location: sampler2d texture: metalness (same as: SHADER_LOC_MAP_SPECULAR)
	add_enum(SHADER_LOC_MAP_METALNESS)

	; Shader location: sampler2d texture: normal
	add_enum(SHADER_LOC_MAP_NORMAL)

	; Shader location: sampler2d texture: roughness
	add_enum(SHADER_LOC_MAP_ROUGHNESS)

	; Shader location: sampler2d texture: occlusion
	add_enum(SHADER_LOC_MAP_OCCLUSION)

	; Shader location: sampler2d texture: emission
	add_enum(SHADER_LOC_MAP_EMISSION)

	; Shader location: sampler2d texture: height
	add_enum(SHADER_LOC_MAP_HEIGHT)

	; Shader location: samplerCube texture: cubemap
	add_enum(SHADER_LOC_MAP_CUBEMAP)

	; Shader location: samplerCube texture: irradiance
	add_enum(SHADER_LOC_MAP_IRRADIANCE)

	; Shader location: samplerCube texture: prefilter
	add_enum(SHADER_LOC_MAP_PREFILTER)

	; Shader location: sampler2d texture: brdf
	add_enum(SHADER_LOC_MAP_BRDF)

	; Shader location: vertex attribute: boneIds
	add_enum(SHADER_LOC_VERTEX_BONEIDS)

	; Shader location: vertex attribute: boneWeights
	add_enum(SHADER_LOC_VERTEX_BONEWEIGHTS)

	; Shader location: array of matrices uniform: boneMatrices
	add_enum(SHADER_LOC_BONE_MATRICES)

	; Shader location: vertex attribute: instanceTransform
	add_enum(SHADER_LOC_VERTEX_INSTANCE_TX)

; Shader uniform data type
; enum ShaderUniformDataType

	reset_enum_value(0)

	; Shader uniform type: float
	add_enum(SHADER_UNIFORM_FLOAT)

	; Shader uniform type: vec2 (2 float)
	add_enum(SHADER_UNIFORM_VEC2)

	; Shader uniform type: vec3 (3 float)
	add_enum(SHADER_UNIFORM_VEC3)

	; Shader uniform type: vec4 (4 float)
	add_enum(SHADER_UNIFORM_VEC4)

	; Shader uniform type: int
	add_enum(SHADER_UNIFORM_INT)

	; Shader uniform type: ivec2 (2 int)
	add_enum(SHADER_UNIFORM_IVEC2)

	; Shader uniform type: ivec3 (3 int)
	add_enum(SHADER_UNIFORM_IVEC3)

	; Shader uniform type: ivec4 (4 int)
	add_enum(SHADER_UNIFORM_IVEC4)

	; Shader uniform type: unsigned int
	add_enum(SHADER_UNIFORM_UINT)

	; Shader uniform type: uivec2 (2 unsigned int)
	add_enum(SHADER_UNIFORM_UIVEC2)

	; Shader uniform type: uivec3 (3 unsigned int)
	add_enum(SHADER_UNIFORM_UIVEC3)

	; Shader uniform type: uivec4 (4 unsigned int)
	add_enum(SHADER_UNIFORM_UIVEC4)

	; Shader uniform type: sampler2d
	add_enum(SHADER_UNIFORM_SAMPLER2D)

; Shader attribute data types
; enum ShaderAttributeDataType

	reset_enum_value(0)

	; Shader attribute type: float
	add_enum(SHADER_ATTRIB_FLOAT)

	; Shader attribute type: vec2 (2 float)
	add_enum(SHADER_ATTRIB_VEC2)

	; Shader attribute type: vec3 (3 float)
	add_enum(SHADER_ATTRIB_VEC3)

	; Shader attribute type: vec4 (4 float)
	add_enum(SHADER_ATTRIB_VEC4)

; Pixel formats
; NOTE: Support depends on OpenGL version and platform
; enum PixelFormat

	reset_enum_value(1)

	; 8 bit per pixel (no alpha)
	add_enum(PIXELFORMAT_UNCOMPRESSED_GRAYSCALE)

	; 8*2 bpp (2 channels)
	add_enum(PIXELFORMAT_UNCOMPRESSED_GRAY_ALPHA)

	; 16 bpp
	add_enum(PIXELFORMAT_UNCOMPRESSED_R5G6B5)

	; 24 bpp
	add_enum(PIXELFORMAT_UNCOMPRESSED_R8G8B8)

	; 16 bpp (1 bit alpha)
	add_enum(PIXELFORMAT_UNCOMPRESSED_R5G5B5A1)

	; 16 bpp (4 bit alpha)
	add_enum(PIXELFORMAT_UNCOMPRESSED_R4G4B4A4)

	; 32 bpp
	add_enum(PIXELFORMAT_UNCOMPRESSED_R8G8B8A8)

	; 32 bpp (1 channel - float)
	add_enum(PIXELFORMAT_UNCOMPRESSED_R32)

	; 32*3 bpp (3 channels - float)
	add_enum(PIXELFORMAT_UNCOMPRESSED_R32G32B32)

	; 32*4 bpp (4 channels - float)
	add_enum(PIXELFORMAT_UNCOMPRESSED_R32G32B32A32)

	; 16 bpp (1 channel - half float)
	add_enum(PIXELFORMAT_UNCOMPRESSED_R16)

	; 16*3 bpp (3 channels - half float)
	add_enum(PIXELFORMAT_UNCOMPRESSED_R16G16B16)

	; 16*4 bpp (4 channels - half float)
	add_enum(PIXELFORMAT_UNCOMPRESSED_R16G16B16A16)

	; 4 bpp (no alpha)
	add_enum(PIXELFORMAT_COMPRESSED_DXT1_RGB)

	; 4 bpp (1 bit alpha)
	add_enum(PIXELFORMAT_COMPRESSED_DXT1_RGBA)

	; 8 bpp
	add_enum(PIXELFORMAT_COMPRESSED_DXT3_RGBA)

	; 8 bpp
	add_enum(PIXELFORMAT_COMPRESSED_DXT5_RGBA)

	; 4 bpp
	add_enum(PIXELFORMAT_COMPRESSED_ETC1_RGB)

	; 4 bpp
	add_enum(PIXELFORMAT_COMPRESSED_ETC2_RGB)

	; 8 bpp
	add_enum(PIXELFORMAT_COMPRESSED_ETC2_EAC_RGBA)

	; 4 bpp
	add_enum(PIXELFORMAT_COMPRESSED_PVRT_RGB)

	; 4 bpp
	add_enum(PIXELFORMAT_COMPRESSED_PVRT_RGBA)

	; 8 bpp
	add_enum(PIXELFORMAT_COMPRESSED_ASTC_4x4_RGBA)

	; 2 bpp
	add_enum(PIXELFORMAT_COMPRESSED_ASTC_8x8_RGBA)

; Texture parameters: filter mode
; NOTE 1: Filtering considers mipmaps if available in the texture
; NOTE 2: Filter is accordingly set for minification and magnification
; enum TextureFilter

	reset_enum_value(0)

	; No filter, just pixel approximation
	add_enum(TEXTURE_FILTER_POINT)

	; Linear filtering
	add_enum(TEXTURE_FILTER_BILINEAR)

	; Trilinear filtering (linear with mipmaps)
	add_enum(TEXTURE_FILTER_TRILINEAR)

	; Anisotropic filtering 4x
	add_enum(TEXTURE_FILTER_ANISOTROPIC_4X)

	; Anisotropic filtering 8x
	add_enum(TEXTURE_FILTER_ANISOTROPIC_8X)

	; Anisotropic filtering 16x
	add_enum(TEXTURE_FILTER_ANISOTROPIC_16X)

; Texture parameters: wrap mode
; enum TextureWrap

	reset_enum_value(0)

	; Repeats texture in tiled mode
	add_enum(TEXTURE_WRAP_REPEAT)

	; Clamps texture to edge pixel in tiled mode
	add_enum(TEXTURE_WRAP_CLAMP)

	; Mirrors and repeats the texture in tiled mode
	add_enum(TEXTURE_WRAP_MIRROR_REPEAT)

	; Mirrors and clamps to border the texture in tiled mode
	add_enum(TEXTURE_WRAP_MIRROR_CLAMP)

; Cubemap layouts
; enum CubemapLayout

	reset_enum_value(0)

	; Automatically detect layout type
	add_enum(CUBEMAP_LAYOUT_AUTO_DETECT)

	; Layout is defined by a vertical line with faces
	add_enum(CUBEMAP_LAYOUT_LINE_VERTICAL)

	; Layout is defined by a horizontal line with faces
	add_enum(CUBEMAP_LAYOUT_LINE_HORIZONTAL)

	; Layout is defined by a 3x4 cross with cubemap faces
	add_enum(CUBEMAP_LAYOUT_CROSS_THREE_BY_FOUR)

	; Layout is defined by a 4x3 cross with cubemap faces
	add_enum(CUBEMAP_LAYOUT_CROSS_FOUR_BY_THREE)

; Font type, defines generation method
; enum FontType

	reset_enum_value(0)

	; Default font generation, anti-aliased
	add_enum(FONT_DEFAULT)

	; Bitmap font generation, no anti-aliasing
	add_enum(FONT_BITMAP)

	; SDF font generation, requires external shader
	add_enum(FONT_SDF)

; Color blending modes (pre-defined)
; enum BlendMode

	reset_enum_value(0)

	; Blend textures considering alpha (default)
	add_enum(BLEND_ALPHA)

	; Blend textures adding colors
	add_enum(BLEND_ADDITIVE)

	; Blend textures multiplying colors
	add_enum(BLEND_MULTIPLIED)

	; Blend textures adding colors (alternative)
	add_enum(BLEND_ADD_COLORS)

	; Blend textures subtracting colors (alternative)
	add_enum(BLEND_SUBTRACT_COLORS)

	; Blend premultiplied textures considering alpha
	add_enum(BLEND_ALPHA_PREMULTIPLY)

	; Blend textures using custom src/dst factors (use rlSetBlendFactors())
	add_enum(BLEND_CUSTOM)

	; Blend textures using custom rgb/alpha separate src/dst factors (use rlSetBlendFactorsSeparate())
	add_enum(BLEND_CUSTOM_SEPARATE)

; Gesture
; NOTE: Provided as bit-wise flags to enable only desired gestures
; enum Gesture

	; No gesture
	add_enum_value(GESTURE_NONE, 0)

	; Tap gesture
	add_enum_value(GESTURE_TAP, 1)

	; Double tap gesture
	add_enum_value(GESTURE_DOUBLETAP, 2)

	; Hold gesture
	add_enum_value(GESTURE_HOLD, 4)

	; Drag gesture
	add_enum_value(GESTURE_DRAG, 8)

	; Swipe right gesture
	add_enum_value(GESTURE_SWIPE_RIGHT, 16)

	; Swipe left gesture
	add_enum_value(GESTURE_SWIPE_LEFT, 32)

	; Swipe up gesture
	add_enum_value(GESTURE_SWIPE_UP, 64)

	; Swipe down gesture
	add_enum_value(GESTURE_SWIPE_DOWN, 128)

	; Pinch in gesture
	add_enum_value(GESTURE_PINCH_IN, 256)

	; Pinch out gesture
	add_enum_value(GESTURE_PINCH_OUT, 512)

; Camera system modes
; enum CameraMode

	reset_enum_value(0)

	; Camera custom, controlled by user (UpdateCamera() does nothing)
	add_enum(CAMERA_CUSTOM)

	; Camera free mode
	add_enum(CAMERA_FREE)

	; Camera orbital, around target, zoom supported
	add_enum(CAMERA_ORBITAL)

	; Camera first person
	add_enum(CAMERA_FIRST_PERSON)

	; Camera third person
	add_enum(CAMERA_THIRD_PERSON)

; Camera projection
; enum CameraProjection

	reset_enum_value(0)

	; Perspective projection
	add_enum(CAMERA_PERSPECTIVE)

	; Orthographic projection
	add_enum(CAMERA_ORTHOGRAPHIC)

; N-patch layout
; enum NPatchLayout

	reset_enum_value(0)

	; Npatch layout: 3x3 tiles
	add_enum(NPATCH_NINE_PATCH)

	; Npatch layout: 1x3 tiles
	add_enum(NPATCH_THREE_PATCH_VERTICAL)

	; Npatch layout: 3x1 tiles
	add_enum(NPATCH_THREE_PATCH_HORIZONTAL)

; Add backwards compatibility support for deprecated names

	%xdefine MOUSE_LEFT_BUTTON MOUSE_BUTTON_LEFT
	%xdefine MOUSE_RIGHT_BUTTON MOUSE_BUTTON_RIGHT
	%xdefine MOUSE_MIDDLE_BUTTON MOUSE_BUTTON_MIDDLE

	%xdefine MATERIAL_MAP_DIFFUSE MATERIAL_MAP_ALBEDO
	%xdefine MATERIAL_MAP_SPECULAR MATERIAL_MAP_METALNESS

	%xdefine SHADER_LOC_MAP_DIFFUSE SHADER_LOC_MAP_ALBEDO
	%xdefine SHADER_LOC_MAP_SPECULAR SHADER_LOC_MAP_METALNESS


%endif ; RAY_ENUMS_INC
