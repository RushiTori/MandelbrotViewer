%ifndef RTEXTURES_INC
%define RTEXTURES_INC

; Image loading functions
; NOTE: These functions do not require GPU access

	; Load image from file into CPU memory (RAM)
	; Image LoadImage(const char* fileName);
	extern LoadImage

	; Load image from RAW file data
	; Image LoadImageRaw(const char* fileName, int width, int height, int format, int headerSize);
	extern LoadImageRaw

	; Load image sequence from file (frames appended to image.data)
	; Image LoadImageAnim(const char* fileName, int* frames);
	extern LoadImageAnim

	; Load image sequence from memory buffer
	; Image LoadImageAnimFromMemory(const char* fileType, const unsigned char* fileData, int dataSize, int* frames);
	extern LoadImageAnimFromMemory

	; Load image from memory buffer, fileType refers to extension: i.e. '.png'
	; Image LoadImageFromMemory(const char* fileType, const unsigned char* fileData, int dataSize);
	extern LoadImageFromMemory

	; Load image from GPU texture data
	; Image LoadImageFromTexture(Texture2D texture);
	extern LoadImageFromTexture

	; Load image from screen buffer and (screenshot)
	; Image LoadImageFromScreen(void);
	extern LoadImageFromScreen

	; Check if an image is valid (data and parameters)
	; bool IsImageValid(Image image);
	extern IsImageValid

	; Unload image from CPU memory (RAM)
	; void UnloadImage(Image image);
	extern UnloadImage

	; Export image data to file, returns true on success
	; bool ExportImage(Image image, const char* fileName);
	extern ExportImage

	; Export image to memory buffer
	; unsigned char* ExportImageToMemory(Image image, const char* fileType, int* fileSize);
	extern ExportImageToMemory

	; Export image as code file defining an array of bytes, returns true on success
	; bool ExportImageAsCode(Image image, const char* fileName);
	extern ExportImageAsCode

; Image generation functions

	; Generate image: plain color
	; Image GenImageColor(int width, int height, Color color);
	extern GenImageColor

	; Generate image: linear gradient, direction in degrees [0..360], 0=Vertical gradient
	; Image GenImageGradientLinear(int width, int height, int direction, Color start, Color end);
	extern GenImageGradientLinear

	; Generate image: radial gradient
	; Image GenImageGradientRadial(int width, int height, float density, Color inner, Color outer);
	extern GenImageGradientRadial

	; Generate image: square gradient
	; Image GenImageGradientSquare(int width, int height, float density, Color inner, Color outer);
	extern GenImageGradientSquare

	; Generate image: checked
	; Image GenImageChecked(int width, int height, int checksX, int checksY, Color col1, Color col2);
	extern GenImageChecked

	; Generate image: white noise
	; Image GenImageWhiteNoise(int width, int height, float factor);
	extern GenImageWhiteNoise

	; Generate image: perlin noise
	; Image GenImagePerlinNoise(int width, int height, int offsetX, int offsetY, float scale);
	extern GenImagePerlinNoise

	; Generate image: cellular algorithm, bigger tileSize means bigger cells
	; Image GenImageCellular(int width, int height, int tileSize);
	extern GenImageCellular

	; Generate image: grayscale image from text data
	; Image GenImageText(int width, int height, const char* text);
	extern GenImageText

; Image manipulation functions

	; Create an image duplicate (useful for transformations)
	; Image ImageCopy(Image image);
	extern ImageCopy

	; Create an image from another image piece
	; Image ImageFromImage(Image image, Rectangle rec);
	extern ImageFromImage

	; Create an image from a selected channel of another image (GRAYSCALE)
	; Image ImageFromChannel(Image image, int selectedChannel);
	extern ImageFromChannel

	; Create an image from text (default font)
	; Image ImageText(const char* text, int fontSize, Color color);
	extern ImageText

	; Create an image from text (custom sprite font)
	; Image ImageTextEx(Font font, const char* text, float fontSize, float spacing, Color tint);
	extern ImageTextEx

	; Convert image data to desired format
	; void ImageFormat(Image* image, int newFormat);
	extern ImageFormat

	; Convert image to POT (power-of-two)
	; void ImageToPOT(Image* image, Color fill);
	extern ImageToPOT

	; Crop an image to a defined rectangle
	; void ImageCrop(Image* image, Rectangle crop);
	extern ImageCrop

	; Crop image depending on alpha value
	; void ImageAlphaCrop(Image* image, float threshold);
	extern ImageAlphaCrop

	; Clear alpha channel to desired color
	; void ImageAlphaClear(Image* image, Color color, float threshold);
	extern ImageAlphaClear

	; Apply alpha mask to image
	; void ImageAlphaMask(Image* image, Image alphaMask);
	extern ImageAlphaMask

	; Premultiply alpha channel
	; void ImageAlphaPremultiply(Image* image);
	extern ImageAlphaPremultiply

	; Apply Gaussian blur using a box blur approximation
	; void ImageBlurGaussian(Image* image, int blurSize);
	extern ImageBlurGaussian

	; Apply custom square convolution kernel to image
	; void ImageKernelConvolution(Image* image, const float* kernel, int kernelSize);
	extern ImageKernelConvolution

	; Resize image (Bicubic scaling algorithm)
	; void ImageResize(Image* image, int newWidth, int newHeight);
	extern ImageResize

	; Resize image (Nearest-Neighbor scaling algorithm)
	; void ImageResizeNN(Image* image, int newWidth, int newHeight);
	extern ImageResizeNN

	; Resize canvas and fill with color
	; void ImageResizeCanvas(Image* image, int newWidth, int newHeight, int offsetX, int offsetY, Color fill);
	extern ImageResizeCanvas

	; Compute all mipmap levels for a provided image
	; void ImageMipmaps(Image* image);
	extern ImageMipmaps

	; Dither image data to 16bpp or lower (Floyd-Steinberg dithering)
	; void ImageDither(Image* image, int rBpp, int gBpp, int bBpp, int aBpp);
	extern ImageDither

	; Flip image vertically
	; void ImageFlipVertical(Image* image);
	extern ImageFlipVertical

	; Flip image horizontally
	; void ImageFlipHorizontal(Image* image);
	extern ImageFlipHorizontal

	; Rotate image by input angle in degrees (-359 to 359)
	; void ImageRotate(Image* image, int degrees);
	extern ImageRotate

	; Rotate image clockwise 90deg
	; void ImageRotateCW(Image* image);
	extern ImageRotateCW

	; Rotate image counter-clockwise 90deg
	; void ImageRotateCCW(Image* image);
	extern ImageRotateCCW

	; Modify image color: tint
	; void ImageColorTint(Image* image, Color color);
	extern ImageColorTint

	; Modify image color: invert
	; void ImageColorInvert(Image* image);
	extern ImageColorInvert

	; Modify image color: grayscale
	; void ImageColorGrayscale(Image* image);
	extern ImageColorGrayscale

	; Modify image color: contrast (-100 to 100)
	; void ImageColorContrast(Image* image, float contrast);
	extern ImageColorContrast

	; Modify image color: brightness (-255 to 255)
	; void ImageColorBrightness(Image* image, int brightness);
	extern ImageColorBrightness

	; Modify image color: replace color
	; void ImageColorReplace(Image* image, Color color, Color replace);
	extern ImageColorReplace

	; Load color data from image as a Color array (RGBA - 32bit)
	; Color* LoadImageColors(Image image);
	extern LoadImageColors

	; Load colors palette from image as a Color array (RGBA - 32bit)
	; Color* LoadImagePalette(Image image, int maxPaletteSize, int* colorCount);
	extern LoadImagePalette

	; Unload color data loaded with LoadImageColors()
	; void UnloadImageColors(Color* colors);
	extern UnloadImageColors

	; Unload colors palette loaded with LoadImagePalette()
	; void UnloadImagePalette(Color* colors);
	extern UnloadImagePalette

	; Get image alpha border rectangle
	; Rectangle GetImageAlphaBorder(Image image, float threshold);
	extern GetImageAlphaBorder

	; Get image pixel color at (x, y) position
	; Color GetImageColor(Image image, int x, int y);
	extern GetImageColor

; Image drawing functions
; NOTE: Image software-rendering functions (CPU)

	; Clear image background with given color
	; void ImageClearBackground(Image* dst, Color color);
	extern ImageClearBackground

	; Draw pixel within an image
	; void ImageDrawPixel(Image* dst, int posX, int posY, Color color);
	extern ImageDrawPixel

	; Draw pixel within an image (Vector version)
	; void ImageDrawPixelV(Image* dst, Vector2 position, Color color);
	extern ImageDrawPixelV

	; Draw line within an image
	; void ImageDrawLine(Image* dst, int startPosX, int startPosY, int endPosX, int endPosY, Color color);
	extern ImageDrawLine

	; Draw line within an image (Vector version)
	; void ImageDrawLineV(Image* dst, Vector2 start, Vector2 end, Color color);
	extern ImageDrawLineV

	; Draw a line defining thickness within an image
	; void ImageDrawLineEx(Image* dst, Vector2 start, Vector2 end, int thick, Color color);
	extern ImageDrawLineEx

	; Draw a filled circle within an image
	; void ImageDrawCircle(Image* dst, int centerX, int centerY, int radius, Color color);
	extern ImageDrawCircle

	; Draw a filled circle within an image (Vector version)
	; void ImageDrawCircleV(Image* dst, Vector2 center, int radius, Color color);
	extern ImageDrawCircleV

	; Draw circle outline within an image
	; void ImageDrawCircleLines(Image* dst, int centerX, int centerY, int radius, Color color);
	extern ImageDrawCircleLines

	; Draw circle outline within an image (Vector version)
	; void ImageDrawCircleLinesV(Image* dst, Vector2 center, int radius, Color color);
	extern ImageDrawCircleLinesV

	; Draw rectangle within an image
	; void ImageDrawRectangle(Image* dst, int posX, int posY, int width, int height, Color color);
	extern ImageDrawRectangle

	; Draw rectangle within an image (Vector version)
	; void ImageDrawRectangleV(Image* dst, Vector2 position, Vector2 size, Color color);
	extern ImageDrawRectangleV

	; Draw rectangle within an image
	; void ImageDrawRectangleRec(Image* dst, Rectangle rec, Color color);
	extern ImageDrawRectangleRec

	; Draw rectangle lines within an image
	; void ImageDrawRectangleLines(Image* dst, Rectangle rec, int thick, Color color);
	extern ImageDrawRectangleLines

	; Draw triangle within an image
	; void ImageDrawTriangle(Image* dst, Vector2 v1, Vector2 v2, Vector2 v3, Color color);
	extern ImageDrawTriangle

	; Draw triangle with interpolated colors within an image
	; void ImageDrawTriangleEx(Image* dst, Vector2 v1, Vector2 v2, Vector2 v3, Color c1, Color c2, Color c3);
	extern ImageDrawTriangleEx

	; Draw triangle outline within an image
	; void ImageDrawTriangleLines(Image* dst, Vector2 v1, Vector2 v2, Vector2 v3, Color color);
	extern ImageDrawTriangleLines

	; Draw a triangle fan defined by points within an image (first vertex is the center)
	; void ImageDrawTriangleFan(Image* dst, Vector2* points, int pointCount, Color color);
	extern ImageDrawTriangleFan

	; Draw a triangle strip defined by points within an image
	; void ImageDrawTriangleStrip(Image* dst, Vector2* points, int pointCount, Color color);
	extern ImageDrawTriangleStrip

	; Draw a source image within a destination image (tint applied to source)
	; void ImageDraw(Image* dst, Image src, Rectangle srcRec, Rectangle dstRec, Color tint);
	extern ImageDraw

	; Draw text (using default font) within an image (destination)
	; void ImageDrawText(Image* dst, const char* text, int posX, int posY, int fontSize, Color color);
	extern ImageDrawText

	; Draw text (custom sprite font) within an image (destination)
	; void ImageDrawTextEx(Image* dst, Font font, const char* text, Vector2 position, float fontSize, float spacing, Color tint);
	extern ImageDrawTextEx

; Texture loading functions
; NOTE: These functions require GPU access

	; Load texture from file into GPU memory (VRAM)
	; Texture2D LoadTexture(const char* fileName);
	extern LoadTexture

	; Load texture from image data
	; Texture2D LoadTextureFromImage(Image image);
	extern LoadTextureFromImage

	; Load cubemap from image, multiple image cubemap layouts supported
	; TextureCubemap LoadTextureCubemap(Image image, int layout);
	extern LoadTextureCubemap

	; Load texture for rendering (framebuffer)
	; RenderTexture2D LoadRenderTexture(int width, int height);
	extern LoadRenderTexture

	; Check if a texture is valid (loaded in GPU)
	; bool IsTextureValid(Texture2D texture);
	extern IsTextureValid

	; Unload texture from GPU memory (VRAM)
	; void UnloadTexture(Texture2D texture);
	extern UnloadTexture

	; Check if a render texture is valid (loaded in GPU)
	; bool IsRenderTextureValid(RenderTexture2D target);
	extern IsRenderTextureValid

	; Unload render texture from GPU memory (VRAM)
	; void UnloadRenderTexture(RenderTexture2D target);
	extern UnloadRenderTexture

	; Update GPU texture with new data
	; void UpdateTexture(Texture2D texture, const void* pixels);
	extern UpdateTexture

	; Update GPU texture rectangle with new data
	; void UpdateTextureRec(Texture2D texture, Rectangle rec, const void* pixels);
	extern UpdateTextureRec

; Texture configuration functions

	; Generate GPU mipmaps for a texture
	; void GenTextureMipmaps(Texture2D* texture);
	extern GenTextureMipmaps

	; Set texture scaling filter mode
	; void SetTextureFilter(Texture2D texture, int filter);
	extern SetTextureFilter

	; Set texture wrapping mode
	; void SetTextureWrap(Texture2D texture, int wrap);
	extern SetTextureWrap

; Texture drawing functions

	; Draw a Texture2D
	; void DrawTexture(Texture2D texture, int posX, int posY, Color tint);
	extern DrawTexture

	; Draw a Texture2D with position defined as Vector2
	; void DrawTextureV(Texture2D texture, Vector2 position, Color tint);
	extern DrawTextureV

	; Draw a Texture2D with extended parameters
	; void DrawTextureEx(Texture2D texture, Vector2 position, float rotation, float scale, Color tint);
	extern DrawTextureEx

	; Draw a part of a texture defined by a rectangle
	; void DrawTextureRec(Texture2D texture, Rectangle source, Vector2 position, Color tint);
	extern DrawTextureRec

	; Draw a part of a texture defined by a rectangle with 'pro' parameters
	; void DrawTexturePro(Texture2D texture, Rectangle source, Rectangle dest, Vector2 origin, float rotation, Color tint);
	extern DrawTexturePro

	; Draws a texture (or part of it) that stretches or shrinks nicely
	; void DrawTextureNPatch(Texture2D texture, NPatchInfo nPatchInfo, Rectangle dest, Vector2 origin, float rotation, Color tint);
	extern DrawTextureNPatch

; Color/pixel related functions

	; Check if two colors are equal
	; bool ColorIsEqual(Color col1, Color col2);
	extern ColorIsEqual

	; Get color with alpha applied, alpha goes from 0.0f to 1.0f
	; Color Fade(Color color, float alpha);
	extern Fade

	; Get hexadecimal value for a Color (0xRRGGBBAA)
	; int ColorToInt(Color color);
	extern ColorToInt

	; Get Color normalized as float [0..1]
	; Vector4 ColorNormalize(Color color);
	extern ColorNormalize

	; Get Color from normalized values [0..1]
	; Color ColorFromNormalized(Vector4 normalized);
	extern ColorFromNormalized

	; Get HSV values for a Color, hue [0..360], saturation/value [0..1]
	; Vector3 ColorToHSV(Color color);
	extern ColorToHSV

	; Get a Color from HSV values, hue [0..360], saturation/value [0..1]
	; Color ColorFromHSV(float hue, float saturation, float value);
	extern ColorFromHSV

	; Get color multiplied with another color
	; Color ColorTint(Color color, Color tint);
	extern ColorTint

	; Get color with brightness correction, brightness factor goes from -1.0f to 1.0f
	; Color ColorBrightness(Color color, float factor);
	extern ColorBrightness

	; Get color with contrast correction, contrast values between -1.0f and 1.0f
	; Color ColorContrast(Color color, float contrast);
	extern ColorContrast

	; Get color with alpha applied, alpha goes from 0.0f to 1.0f
	; Color ColorAlpha(Color color, float alpha);
	extern ColorAlpha

	; Get src alpha-blended into dst color with tint
	; Color ColorAlphaBlend(Color dst, Color src, Color tint);
	extern ColorAlphaBlend

	; Get color lerp interpolation between two colors, factor [0.0f..1.0f]
	; Color ColorLerp(Color color1, Color color2, float factor);
	extern ColorLerp

	; Get Color structure from hexadecimal value
	; Color GetColor(unsigned int hexValue);
	extern GetColor

	; Get Color from a source pixel pointer of certain format
	; Color GetPixelColor(void* srcPtr, int format);
	extern GetPixelColor

	; Set color formatted into destination pixel pointer
	; void SetPixelColor(void* dstPtr, Color color, int format);
	extern SetPixelColor

	; Get pixel data size in bytes for certain format
	; int GetPixelDataSize(int width, int height, int format);
	extern GetPixelDataSize

%endif ; RTEXTURES_INC
