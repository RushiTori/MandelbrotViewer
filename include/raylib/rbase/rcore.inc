%ifndef RCORE_INC
%define RCORE_INC

; Window-related functions

	; Initialize window and OpenGL context
	; void InitWindow(int width, int height, const char* title);
	extern InitWindow

	; Close window and unload OpenGL context
	; void CloseWindow(void);
	extern CloseWindow

	; Check if application should close (KEY_ESCAPE pressed or windows close icon clicked)
	; bool WindowShouldClose(void);
	extern WindowShouldClose

	; Check if window has been initialized successfully
	; bool IsWindowReady(void);
	extern IsWindowReady

	; Check if window is currently fullscreen
	; bool IsWindowFullscreen(void);
	extern IsWindowFullscreen

	; Check if window is currently hidden
	; bool IsWindowHidden(void);
	extern IsWindowHidden

	; Check if window is currently minimized
	; bool IsWindowMinimized(void);
	extern IsWindowMinimized

	; Check if window is currently maximized
	; bool IsWindowMaximized(void);
	extern IsWindowMaximized

	; Check if window is currently focused
	; bool IsWindowFocused(void);
	extern IsWindowFocused

	; Check if window has been resized last frame
	; bool IsWindowResized(void);
	extern IsWindowResized

	; Check if one specific window flag is enabled
	; bool IsWindowState(unsigned int flag);
	extern IsWindowState

	; Set window configuration state using flags
	; void SetWindowState(unsigned int flags);
	extern SetWindowState

	; Clear window configuration state flags
	; void ClearWindowState(unsigned int flags);
	extern ClearWindowState

	; Toggle window state: fullscreen/windowed, resizes monitor to match window resolution
	; void ToggleFullscreen(void);
	extern ToggleFullscreen

	; Toggle window state: borderless windowed, resizes window to match monitor resolution
	; void ToggleBorderlessWindowed(void);
	extern ToggleBorderlessWindowed

	; Set window state: maximized, if resizable
	; void MaximizeWindow(void);
	extern MaximizeWindow

	; Set window state: minimized, if resizable
	; void MinimizeWindow(void);
	extern MinimizeWindow

	; Set window state: not minimized/maximized
	; void RestoreWindow(void);
	extern RestoreWindow

	; Set icon for window (single image, RGBA 32bit)
	; void SetWindowIcon(Image image);
	extern SetWindowIcon

	; Set icon for window (multiple images, RGBA 32bit)
	; void SetWindowIcons(Image* images, int count);
	extern SetWindowIcons

	; Set title for window
	; void SetWindowTitle(const char* title);
	extern SetWindowTitle

	; Set window position on screen
	; void SetWindowPosition(int x, int y);
	extern SetWindowPosition

	; Set monitor for the current window
	; void SetWindowMonitor(int monitor);
	extern SetWindowMonitor

	; Set window minimum dimensions (for FLAG_WINDOW_RESIZABLE)
	; void SetWindowMinSize(int width, int height);
	extern SetWindowMinSize

	; Set window maximum dimensions (for FLAG_WINDOW_RESIZABLE)
	; void SetWindowMaxSize(int width, int height);
	extern SetWindowMaxSize

	; Set window dimensions
	; void SetWindowSize(int width, int height);
	extern SetWindowSize

	; Set window opacity [0.0f..1.0f]
	; void SetWindowOpacity(float opacity);
	extern SetWindowOpacity

	; Set window focused
	; void SetWindowFocused(void);
	extern SetWindowFocused

	; Get native window handle
	; void* GetWindowHandle(void);
	extern GetWindowHandle

	; Get current screen width
	; int GetScreenWidth(void);
	extern GetScreenWidth

	; Get current screen height
	; int GetScreenHeight(void);
	extern GetScreenHeight

	; Get current render width (it considers HiDPI)
	; int GetRenderWidth(void);
	extern GetRenderWidth

	; Get current render height (it considers HiDPI)
	; int GetRenderHeight(void);
	extern GetRenderHeight

	; Get number of connected monitors
	; int GetMonitorCount(void);
	extern GetMonitorCount

	; Get current monitor where window is placed
	; int GetCurrentMonitor(void);
	extern GetCurrentMonitor

	; Get specified monitor position
	; Vector2 GetMonitorPosition(int monitor);
	extern GetMonitorPosition

	; Get specified monitor width (current video mode used by monitor)
	; int GetMonitorWidth(int monitor);
	extern GetMonitorWidth

	; Get specified monitor height (current video mode used by monitor)
	; int GetMonitorHeight(int monitor);
	extern GetMonitorHeight

	; Get specified monitor physical width in millimetres
	; int GetMonitorPhysicalWidth(int monitor);
	extern GetMonitorPhysicalWidth

	; Get specified monitor physical height in millimetres
	; int GetMonitorPhysicalHeight(int monitor);
	extern GetMonitorPhysicalHeight

	; Get specified monitor refresh rate
	; int GetMonitorRefreshRate(int monitor);
	extern GetMonitorRefreshRate

	; Get window position XY on monitor
	; Vector2 GetWindowPosition(void);
	extern GetWindowPosition

	; Get window scale DPI factor
	; Vector2 GetWindowScaleDPI(void);
	extern GetWindowScaleDPI

	; Get the human-readable, UTF-8 encoded name of the specified monitor
	; const char* GetMonitorName(int monitor);
	extern GetMonitorName

	; Set clipboard text content
	; void SetClipboardText(const char* text);
	extern SetClipboardText

	; Get clipboard text content
	; const char* GetClipboardText(void);
	extern GetClipboardText

	; Get clipboard image
	; Image GetClipboardImage(void);
	extern GetClipboardImage

	; Enable waiting for events on EndDrawing(), no automatic event polling
	; void EnableEventWaiting(void);
	extern EnableEventWaiting

	; Disable waiting for events on EndDrawing(), automatic events polling
	; void DisableEventWaiting(void);
	extern DisableEventWaiting

; Cursor-related functions
	; Shows cursor
	; void ShowCursor(void);
	extern ShowCursor

	; Hides cursor
	; void HideCursor(void);
	extern HideCursor

	; Check if cursor is not visible
	; bool IsCursorHidden(void);
	extern IsCursorHidden

	; Enables cursor (unlock cursor)
	; void EnableCursor(void);
	extern EnableCursor

	; Disables cursor (lock cursor)
	; void DisableCursor(void);
	extern DisableCursor

	; Check if cursor is on the screen
	; bool IsCursorOnScreen(void);
	extern IsCursorOnScreen

; Drawing-related functions

	; Set background color (framebuffer clear color)
	; void ClearBackground(Color color);
	extern ClearBackground

	; Setup canvas (framebuffer) to start drawing
	; void BeginDrawing(void);
	extern BeginDrawing

	; End canvas drawing and swap buffers (double buffering)
	; void EndDrawing(void);
	extern EndDrawing

	; Begin 2D mode with custom camera (2D)
	; void BeginMode2D(Camera2D camera);
	extern BeginMode2D

	; Ends 2D mode with custom camera
	; void EndMode2D(void);
	extern EndMode2D

	; Begin 3D mode with custom camera (3D)
	; void BeginMode3D(Camera3D camera);
	extern BeginMode3D

	; Ends 3D mode and returns to default 2D orthographic mode
	; void EndMode3D(void);
	extern EndMode3D

	; Begin drawing to render texture
	; void BeginTextureMode(RenderTexture2D target);
	extern BeginTextureMode

	; Ends drawing to render texture
	; void EndTextureMode(void);
	extern EndTextureMode

	; Begin custom shader drawing
	; void BeginShaderMode(Shader shader);
	extern BeginShaderMode

	; End custom shader drawing (use default shader)
	; void EndShaderMode(void);
	extern EndShaderMode

	; Begin blending mode (alpha, additive, multiplied, subtract, custom)
	; void BeginBlendMode(int mode);
	extern BeginBlendMode

	; End blending mode (reset to default: alpha blending)
	; void EndBlendMode(void);
	extern EndBlendMode

	; Begin scissor mode (define screen area for following drawing)
	; void BeginScissorMode(int x, int y, int width, int height);
	extern BeginScissorMode

	; End scissor mode
	; void EndScissorMode(void);
	extern EndScissorMode

	; Begin stereo rendering (requires VR simulator)
	; void BeginVrStereoMode(VrStereoConfig config);
	extern BeginVrStereoMode

	; End stereo rendering (requires VR simulator)
	; void EndVrStereoMode(void);
	extern EndVrStereoMode

; VR stereo config functions for VR simulator

	; Load VR stereo config for VR simulator device parameters
	; VrStereoConfig LoadVrStereoConfig(VrDeviceInfo device);
	extern LoadVrStereoConfig

	; Unload VR stereo config
	; void UnloadVrStereoConfig(VrStereoConfig config);
	extern UnloadVrStereoConfig

; Shader management functions
; NOTE: Shader functionality is not available on OpenGL 1.1

	; Load shader from files and bind default locations
	; Shader LoadShader(const char* vsFileName, const char* fsFileName);
	extern LoadShader

	; Load shader from code strings and bind default locations
	; Shader LoadShaderFromMemory(const char* vsCode, const char* fsCode);
	extern LoadShaderFromMemory

	; Check if a shader is valid (loaded on GPU)
	; bool IsShaderValid(Shader shader);
	extern IsShaderValid

	; Get shader uniform location
	; int GetShaderLocation(Shader shader, const char* uniformName);
	extern GetShaderLocation

	; Get shader attribute location
	; int GetShaderLocationAttrib(Shader shader, const char* attribName);
	extern GetShaderLocationAttrib

	; Set shader uniform value
	; void SetShaderValue(Shader shader, int locIndex, const void* value, int uniformType);
	extern SetShaderValue

	; Set shader uniform value vector
	; void SetShaderValueV(Shader shader, int locIndex, const void* value, int uniformType, int count);
	extern SetShaderValueV

	; Set shader uniform value (matrix 4x4)
	; void SetShaderValueMatrix(Shader shader, int locIndex, Matrix mat);
	extern SetShaderValueMatrix

	; Set shader uniform value for texture (sampler2d)
	; void SetShaderValueTexture(Shader shader, int locIndex, Texture2D texture);
	extern SetShaderValueTexture

	; Unload shader from GPU memory (VRAM)
	; void UnloadShader(Shader shader);
	extern UnloadShader

; Screen-space-related functions

	; Get a ray trace from screen position (i.e mouse)
	; Ray GetScreenToWorldRay(Vector2 position, Camera camera);
	extern GetScreenToWorldRay

	; Get a ray trace from screen position (i.e mouse) in a viewport
	; Ray GetScreenToWorldRayEx(Vector2 position, Camera camera, int width, int height);
	extern GetScreenToWorldRayEx

	; Get the screen space position for a 3d world space position
	; Vector2 GetWorldToScreen(Vector3 position, Camera camera);
	extern GetWorldToScreen

	; Get size position for a 3d world space position
	; Vector2 GetWorldToScreenEx(Vector3 position, Camera camera, int width, int height);
	extern GetWorldToScreenEx

	; Get the screen space position for a 2d camera world space position
	; Vector2 GetWorldToScreen2D(Vector2 position, Camera2D camera);
	extern GetWorldToScreen2D

	; Get the world space position for a 2d camera screen space position
	; Vector2 GetScreenToWorld2D(Vector2 position, Camera2D camera);
	extern GetScreenToWorld2D

	; Get camera transform matrix (view matrix)
	; Matrix GetCameraMatrix(Camera camera);
	extern GetCameraMatrix

	; Get camera 2d transform matrix
	; Matrix GetCameraMatrix2D(Camera2D camera);
	extern GetCameraMatrix2D

; Timing-related functions

	; Set target FPS (maximum)
	; void SetTargetFPS(int fps);
	extern SetTargetFPS

	; Get time in seconds for last frame drawn (delta time)
	; float GetFrameTime(void);
	extern GetFrameTime

	; Get elapsed time in seconds since InitWindow()
	; double GetTime(void);
	extern GetTime

	; Get current FPS
	; int GetFPS(void);
	extern GetFPS

; Custom frame control functions
; NOTE: Those functions are intended for advanced users that want full control over the frame processing
; By default EndDrawing() does this job: draws everything + SwapScreenBuffer() + manage frame timing + PollInputEvents()
; To avoid that behaviour and control frame processes manually, enable in config.h: SUPPORT_CUSTOM_FRAME_CONTROL

	; Swap back buffer with front buffer (screen drawing)
	; void SwapScreenBuffer(void);
	extern SwapScreenBuffer

	; Register all input events
	; void PollInputEvents(void);
	extern PollInputEvents

	; Wait for some time (halt program execution)
	; void WaitTime(double seconds);
	extern WaitTime

	; Random values generation functions
	; Set the seed for the random number generator
	; void SetRandomSeed(unsigned int seed);
	extern SetRandomSeed

	; Get a random value between min and max (both included)
	; int GetRandomValue(int min, int max);
	extern GetRandomValue

	; Load random values sequence, no values repeated
	; int* LoadRandomSequence(unsigned int count, int min, int max);
	extern LoadRandomSequence

	; Unload random values sequence
	; void UnloadRandomSequence(int* sequence);
	extern UnloadRandomSequence

; Misc. functions

	; Takes a screenshot of current screen (filename extension defines format)
	; void TakeScreenshot(const char* fileName);
	extern TakeScreenshot

	; Setup init configuration flags (view FLAGS)
	; void SetConfigFlags(unsigned int flags);
	extern SetConfigFlags

	; Open URL with default system browser (if available)
	; void OpenURL(const char* url);
	extern OpenURL

; NOTE: Following functions implemented in module [utils]
;------------------------------------------------------------------

	; Show trace log messages (LOG_DEBUG, LOG_INFO, LOG_WARNING, LOG_ERROR...)
	; void TraceLog(int logLevel, const char* text, ...);
	extern TraceLog

	; Set the current threshold (minimum) log level
	; void SetTraceLogLevel(int logLevel);
	extern SetTraceLogLevel

	; Internal memory allocator
	; void* MemAlloc(unsigned int size);
	extern MemAlloc

	; Internal memory reallocator
	; void* MemRealloc(void* ptr, unsigned int size);
	extern MemRealloc

	; Internal memory free
	; void MemFree(void* ptr);
	extern MemFree

	; Set custom callbacks
	; WARNING: Callbacks setup is intended for advanced users

		; Set custom trace log
		; void SetTraceLogCallback(TraceLogCallback callback);
		extern SetTraceLogCallback

		; Set custom file binary data loader
		; void SetLoadFileDataCallback(LoadFileDataCallback callback);
		extern SetLoadFileDataCallback

		; Set custom file binary data saver
		; void SetSaveFileDataCallback(SaveFileDataCallback callback);
		extern SetSaveFileDataCallback

		; Set custom file text data loader
		; void SetLoadFileTextCallback(LoadFileTextCallback callback);
		extern SetLoadFileTextCallback

		; Set custom file text data saver
		; void SetSaveFileTextCallback(SaveFileTextCallback callback);
		extern SetSaveFileTextCallback

	; Files management functions

		; Load file data as byte array (read)
		; unsigned char* LoadFileData(const char* fileName, int* dataSize);
		extern LoadFileData

		; Unload file data allocated by LoadFileData()
		; void UnloadFileData(unsigned char* data);
		extern UnloadFileData

		; Save data to file from byte array (write), returns true on success
		; bool SaveFileData(const char* fileName, void* data, int dataSize);
		extern SaveFileData

		; Export data to code (.h), returns true on success
		; bool ExportDataAsCode(const unsigned char* data, int dataSize, const char* fileName);
		extern ExportDataAsCode

		; Load text data from file (read), returns a '\0' terminated string
		; char* LoadFileText(const char* fileName);
		extern LoadFileText

		; Unload file text data allocated by LoadFileText()
		; void UnloadFileText(char* text);
		extern UnloadFileText

		; Save text data to file (write), string must be '\0' terminated, returns true on success
		; bool SaveFileText(const char* fileName, char* text);
		extern SaveFileText

	;------------------------------------------------------------------

; File system functions

	; Check if file exists
	; bool FileExists(const char* fileName);
	extern FileExists

	; Check if a directory path exists
	; bool DirectoryExists(const char* dirPath);
	extern DirectoryExists

	; Check file extension (including point: .png, .wav)
	; bool IsFileExtension(const char* fileName, const char* ext);
	extern IsFileExtension

	; Get file length in bytes (NOTE: GetFileSize() conflicts with windows.h)
	; int GetFileLength(const char* fileName);
	extern GetFileLength

	; Get pointer to extension for a filename string (includes dot: '.png')
	; const char* GetFileExtension(const char* fileName);
	extern GetFileExtension

	; Get pointer to filename for a path string
	; const char* GetFileName(const char* filePath);
	extern GetFileName

	; Get filename string without extension (uses static string)
	; const char* GetFileNameWithoutExt(const char* filePath);
	extern GetFileNameWithoutExt

	; Get full path for a given fileName with path (uses static string)
	; const char* GetDirectoryPath(const char* filePath);
	extern GetDirectoryPath

	; Get previous directory path for a given path (uses static string)
	; const char* GetPrevDirectoryPath(const char* dirPath);
	extern GetPrevDirectoryPath

	; Get current working directory (uses static string)
	; const char* GetWorkingDirectory(void);
	extern GetWorkingDirectory

	; Get the directory of the running application (uses static string)
	; const char* GetApplicationDirectory(void);
	extern GetApplicationDirectory

	; Create directories (including full path requested), returns 0 on success
	; int MakeDirectory(const char* dirPath);
	extern MakeDirectory

	; Change working directory, return true on success
	; bool ChangeDirectory(const char* dir);
	extern ChangeDirectory

	; Check if a given path is a file or a directory
	; bool IsPathFile(const char* path);
	extern IsPathFile

	; Check if fileName is valid for the platform/OS
	; bool IsFileNameValid(const char* fileName);
	extern IsFileNameValid

	; Load directory filepaths
	; FilePathList LoadDirectoryFiles(const char* dirPath);
	extern LoadDirectoryFiles

	; Load directory filepaths with extension filtering and recursive directory scan. Use 'DIR' in the filter string to include directories in the result
	; FilePathList LoadDirectoryFilesEx(const char* basePath, const char* filter, bool scanSubdirs);
	extern LoadDirectoryFilesEx

	; Unload filepaths
	; void UnloadDirectoryFiles(FilePathList files);
	extern UnloadDirectoryFiles

	; Check if a file has been dropped into window
	; bool IsFileDropped(void);
	extern IsFileDropped

	; Load dropped filepaths
	; FilePathList LoadDroppedFiles(void);
	extern LoadDroppedFiles

	; Unload dropped filepaths
	; void UnloadDroppedFiles(FilePathList files);
	extern UnloadDroppedFiles

	; Get file modification time (last write time)
	; long GetFileModTime(const char* fileName);
	extern GetFileModTime

; Compression/Encoding functionality

	; Compress data (DEFLATE algorithm), memory must be MemFree()
	; unsigned char* CompressData(const unsigned char* data, int dataSize, int* compDataSize);
	extern CompressData

	; Decompress data (DEFLATE algorithm), memory must be MemFree()
	; unsigned char* DecompressData(const unsigned char* compData, int compDataSize, int* dataSize);
	extern DecompressData

	; Encode data to Base64 string, memory must be MemFree()
	; char* EncodeDataBase64(const unsigned char* data, int dataSize, int* outputSize);
	extern EncodeDataBase64

	; Decode Base64 string data, memory must be MemFree()
	; unsigned char* DecodeDataBase64(const unsigned char* data, int* outputSize);
	extern DecodeDataBase64

	; Compute CRC32 hash code
	; unsigned int ComputeCRC32(unsigned char* data, int dataSize);
	extern ComputeCRC32

	; Compute MD5 hash code, returns static int[4] (16 bytes)
	; unsigned int* ComputeMD5(unsigned char* data, int dataSize);
	extern ComputeMD5

	; Compute SHA1 hash code, returns static int[5] (20 bytes)
	; unsigned int* ComputeSHA1(unsigned char* data, int dataSize);
	extern ComputeSHA1

; Automation events functionality

	; Load automation events list from file, NULL for empty list, capacity = MAX_AUTOMATION_EVENTS
	; AutomationEventList LoadAutomationEventList(const char* fileName);
	extern LoadAutomationEventList

	; Unload automation events list from file
	; void UnloadAutomationEventList(AutomationEventList list);
	extern UnloadAutomationEventList

	; Export automation events list as text file
	; bool ExportAutomationEventList(AutomationEventList list, const char* fileName);
	extern ExportAutomationEventList

	; Set automation event list to record to
	; void SetAutomationEventList(AutomationEventList* list);
	extern SetAutomationEventList

	; Set automation event internal base frame to start recording
	; void SetAutomationEventBaseFrame(int frame);
	extern SetAutomationEventBaseFrame

	; Start recording automation events (AutomationEventList must be set)
	; void StartAutomationEventRecording(void);
	extern StartAutomationEventRecording

	; Stop recording automation events
	; void StopAutomationEventRecording(void);
	extern StopAutomationEventRecording

	; Play a recorded automation event
	; void PlayAutomationEvent(AutomationEvent event);
	extern PlayAutomationEvent

;------------------------------------------------------------------------------------
; Input Handling Functions (Module: core)
;------------------------------------------------------------------------------------

	; Input-related functions: keyboard
	; Check if a key has been pressed once
	; bool IsKeyPressed(int key);
	extern IsKeyPressed

	; Check if a key has been pressed again
	; bool IsKeyPressedRepeat(int key);
	extern IsKeyPressedRepeat

	; Check if a key is being pressed
	; bool IsKeyDown(int key);
	extern IsKeyDown

	; Check if a key has been released once
	; bool IsKeyReleased(int key);
	extern IsKeyReleased

	; Check if a key is NOT being pressed
	; bool IsKeyUp(int key);
	extern IsKeyUp

	; Get key pressed (keycode), call it multiple times for keys queued, returns 0 when the queue is empty
	; int GetKeyPressed(void);
	extern GetKeyPressed

	; Get char pressed (unicode), call it multiple times for chars queued, returns 0 when the queue is empty
	; int GetCharPressed(void);
	extern GetCharPressed

	; Set a custom key to exit program (default is ESC)
	; void SetExitKey(int key);
	extern SetExitKey

	; Input-related functions: gamepads
	; Check if a gamepad is available
	; bool IsGamepadAvailable(int gamepad);
	extern IsGamepadAvailable

	; Get gamepad internal name id
	; const char* GetGamepadName(int gamepad);
	extern GetGamepadName

	; Check if a gamepad button has been pressed once
	; bool IsGamepadButtonPressed(int gamepad, int button);
	extern IsGamepadButtonPressed

	; Check if a gamepad button is being pressed
	; bool IsGamepadButtonDown(int gamepad, int button);
	extern IsGamepadButtonDown

	; Check if a gamepad button has been released once
	; bool IsGamepadButtonReleased(int gamepad, int button);
	extern IsGamepadButtonReleased

	; Check if a gamepad button is NOT being pressed
	; bool IsGamepadButtonUp(int gamepad, int button);
	extern IsGamepadButtonUp

	; Get the last gamepad button pressed
	; int GetGamepadButtonPressed(void);
	extern GetGamepadButtonPressed

	; Get gamepad axis count for a gamepad
	; int GetGamepadAxisCount(int gamepad);
	extern GetGamepadAxisCount

	; Get axis movement value for a gamepad axis
	; float GetGamepadAxisMovement(int gamepad, int axis);
	extern GetGamepadAxisMovement

	; Set internal gamepad mappings (SDL_GameControllerDB)
	; int SetGamepadMappings(const char* mappings);
	extern SetGamepadMappings

	; Set gamepad vibration for both motors (duration in seconds)
	; void SetGamepadVibration(int gamepad, float leftMotor, float rightMotor, float duration);
	extern SetGamepadVibration

	; Input-related functions: mouse
	; Check if a mouse button has been pressed once
	; bool IsMouseButtonPressed(int button);
	extern IsMouseButtonPressed

	; Check if a mouse button is being pressed
	; bool IsMouseButtonDown(int button);
	extern IsMouseButtonDown

	; Check if a mouse button has been released once
	; bool IsMouseButtonReleased(int button);
	extern IsMouseButtonReleased

	; Check if a mouse button is NOT being pressed
	; bool IsMouseButtonUp(int button);
	extern IsMouseButtonUp

	; Get mouse position X
	; int GetMouseX(void);
	extern GetMouseX

	; Get mouse position Y
	; int GetMouseY(void);
	extern GetMouseY

	; Get mouse position XY
	; Vector2 GetMousePosition(void);
	extern GetMousePosition

	; Get mouse delta between frames
	; Vector2 GetMouseDelta(void);
	extern GetMouseDelta

	; Set mouse position XY
	; void SetMousePosition(int x, int y);
	extern SetMousePosition

	; Set mouse offset
	; void SetMouseOffset(int offsetX, int offsetY);
	extern SetMouseOffset

	; Set mouse scaling
	; void SetMouseScale(float scaleX, float scaleY);
	extern SetMouseScale

	; Get mouse wheel movement for X or Y, whichever is larger
	; float GetMouseWheelMove(void);
	extern GetMouseWheelMove

	; Get mouse wheel movement for both X and Y
	; Vector2 GetMouseWheelMoveV(void);
	extern GetMouseWheelMoveV

	; Set mouse cursor
	; void SetMouseCursor(int cursor);
	extern SetMouseCursor

	; Input-related functions: touch
	; Get touch position X for touch point 0 (relative to screen size)
	; int GetTouchX(void);
	extern GetTouchX

	; Get touch position Y for touch point 0 (relative to screen size)
	; int GetTouchY(void);
	extern GetTouchY

	; Get touch position XY for a touch point index (relative to screen size)
	; Vector2 GetTouchPosition(int index);
	extern GetTouchPosition

	; Get touch point identifier for given index
	; int GetTouchPointId(int index);
	extern GetTouchPointId

	; Get number of touch points
	; int GetTouchPointCount(void);
	extern GetTouchPointCount

	;------------------------------------------------------------------------------------
	; Gestures and Touch Handling Functions (Module: rgestures)
	;------------------------------------------------------------------------------------
	; Enable a set of gestures using flags
	; void SetGesturesEnabled(unsigned int flags);
	extern SetGesturesEnabled

	; Check if a gesture have been detected
	; bool IsGestureDetected(unsigned int gesture);
	extern IsGestureDetected

	; Get latest detected gesture
	; int GetGestureDetected(void);
	extern GetGestureDetected

	; Get gesture hold time in seconds
	; float GetGestureHoldDuration(void);
	extern GetGestureHoldDuration

	; Get gesture drag vector
	; Vector2 GetGestureDragVector(void);
	extern GetGestureDragVector

	; Get gesture drag angle
	; float GetGestureDragAngle(void);
	extern GetGestureDragAngle

	; Get gesture pinch delta
	; Vector2 GetGesturePinchVector(void);
	extern GetGesturePinchVector

	; Get gesture pinch angle
	; float GetGesturePinchAngle(void);
	extern GetGesturePinchAngle

	;------------------------------------------------------------------------------------
	; Camera System Functions (Module: rcamera)
	;------------------------------------------------------------------------------------
	; Update camera position for selected mode
	; void UpdateCamera(Camera* camera, int mode);
	extern UpdateCamera

	; Update camera movement/rotation
	; void UpdateCameraPro(Camera* camera, Vector3 movement, Vector3 rotation, float zoom);
	extern UpdateCameraPro

%endif ; RCORE_INC
