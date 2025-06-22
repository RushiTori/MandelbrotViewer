%ifndef RTEXT_INC
%define RTEXT_INC

; Font loading/unloading functions

	; Get the default Font
	; Font GetFontDefault(void);
	extern GetFontDefault

	; Load font from file into GPU memory (VRAM)
	; Font LoadFont(const char* fileName);
	extern LoadFont

	; Load font from file with extended parameters, use NULL for codepoints and 0 for codepointCount to load the default character set, font size is provided in pixels height
	; Font LoadFontEx(const char* fileName, int fontSize, int* codepoints, int codepointCount);
	extern LoadFontEx

	; Load font from Image (XNA style)
	; Font LoadFontFromImage(Image image, Color key, int firstChar);
	extern LoadFontFromImage

	; Load font from memory buffer, fileType refers to extension: i.e. '.ttf'
	; Font LoadFontFromMemory(const char* fileType, const unsigned char* fileData, int dataSize, int fontSize, int* codepoints, int codepointCount);
	extern LoadFontFromMemory

	; Check if a font is valid (font data loaded, WARNING: GPU texture not checked)
	; bool IsFontValid(Font font);
	extern IsFontValid

	; Load font data for further use
	; GlyphInfo* LoadFontData(const unsigned char* fileData, int dataSize, int fontSize, int* codepoints, int codepointCount, int type);
	extern LoadFontData

	; Generate image font atlas using chars info
	; Image GenImageFontAtlas(const GlyphInfo* glyphs, Rectangle** glyphRecs, int glyphCount, int fontSize, int padding, int packMethod);
	extern GenImageFontAtlas

	; Unload font chars info data (RAM)
	; void UnloadFontData(GlyphInfo* glyphs, int glyphCount);
	extern UnloadFontData

	; Unload font from GPU memory (VRAM)
	; void UnloadFont(Font font);
	extern UnloadFont

	; Export font as code file, returns true on success
	; bool ExportFontAsCode(Font font, const char* fileName);
	extern ExportFontAsCode

; Text drawing functions

	; Draw current FPS
	; void DrawFPS(int posX, int posY);
	extern DrawFPS

	; Draw text (using default font)
	; void DrawText(const char* text, int posX, int posY, int fontSize, Color color);
	extern DrawText

	; Draw text using font and additional parameters
	; void DrawTextEx(Font font, const char* text, Vector2 position, float fontSize, float spacing, Color tint);
	extern DrawTextEx

	; Draw text using Font and pro parameters (rotation)
	; void DrawTextPro(Font font, const char* text, Vector2 position, Vector2 origin, float rotation, float fontSize, float spacing, Color tint);
	extern DrawTextPro

	; Draw one character (codepoint)
	; void DrawTextCodepoint(Font font, int codepoint, Vector2 position, float fontSize, Color tint);
	extern DrawTextCodepoint

	; Draw multiple character (codepoint)
	; void DrawTextCodepoints(Font font, const int* codepoints, int codepointCount, Vector2 position, float fontSize, float spacing, Color tint);
	extern DrawTextCodepoints

; Text font info functions

	; Set vertical line spacing when drawing with line-breaks
	; void SetTextLineSpacing(int spacing);
	extern SetTextLineSpacing

	; Measure string width for default font
	; int MeasureText(const char* text, int fontSize);
	extern MeasureText

	; Measure string size for Font
	; Vector2 MeasureTextEx(Font font, const char* text, float fontSize, float spacing);
	extern MeasureTextEx

	; Get glyph index position in font for a codepoint (unicode character), fallback to '?' if not found
	; int GetGlyphIndex(Font font, int codepoint);
	extern GetGlyphIndex

	; Get glyph font info data for a codepoint (unicode character), fallback to '?' if not found
	; GlyphInfo GetGlyphInfo(Font font, int codepoint);
	extern GetGlyphInfo

	; Get glyph rectangle in font atlas for a codepoint (unicode character), fallback to '?' if not found
	; Rectangle GetGlyphAtlasRec(Font font, int codepoint);
	extern GetGlyphAtlasRec

; Text codepoints management functions (unicode characters)

	; Load UTF-8 text encoded from codepoints array
	; char* LoadUTF8(const int* codepoints, int length);
	extern LoadUTF8

	; Unload UTF-8 text encoded from codepoints array
	; void UnloadUTF8(char* text);
	extern UnloadUTF8

	; Load all codepoints from a UTF-8 text string, codepoints count returned by parameter
	; int* LoadCodepoints(const char* text, int* count);
	extern LoadCodepoints

	; Unload codepoints data from memory
	; void UnloadCodepoints(int* codepoints);
	extern UnloadCodepoints

	; Get total number of codepoints in a UTF-8 encoded string
	; int GetCodepointCount(const char* text);
	extern GetCodepointCount

	; Get next codepoint in a UTF-8 encoded string, 0x3f('?') is returned on failure
	; int GetCodepoint(const char* text, int* codepointSize);
	extern GetCodepoint

	; Get next codepoint in a UTF-8 encoded string, 0x3f('?') is returned on failure
	; int GetCodepointNext(const char* text, int* codepointSize);
	extern GetCodepointNext

	; Get previous codepoint in a UTF-8 encoded string, 0x3f('?') is returned on failure
	; int GetCodepointPrevious(const char* text, int* codepointSize);
	extern GetCodepointPrevious

	; Encode one codepoint into UTF-8 byte array (array length returned as parameter)
	; const char* CodepointToUTF8(int codepoint, int* utf8Size);
	extern CodepointToUTF8

; Text strings management functions (no UTF-8 strings, only byte chars)
; NOTE: Some strings allocate memory internally for returned strings, just be careful!

	; Copy one string to another, returns bytes copied
	; int TextCopy(char* dst, const char* src);
	extern TextCopy

	; Check if two text string are equal
	; bool TextIsEqual(const char* text1, const char* text2);
	extern TextIsEqual

	; Get text length, checks for '\0' ending
	; unsigned int TextLength(const char* text);
	extern TextLength

	; Text formatting with variables (sprintf() style)
	; const char* TextFormat(const char* text, ...);
	extern TextFormat

	; Get a piece of a text string
	; const char* TextSubtext(const char* text, int position, int length);
	extern TextSubtext

	; Replace text string (WARNING: memory must be freed!)
	; char* TextReplace(const char* text, const char* replace, const char* by);
	extern TextReplace

	; Insert text in a position (WARNING: memory must be freed!)
	; char* TextInsert(const char* text, const char* insert, int position);
	extern TextInsert

	; Join text strings with delimiter
	; const char* TextJoin(const char** textList, int count, const char* delimiter);
	extern TextJoin

	; Split text into multiple strings
	; const char** TextSplit(const char* text, char delimiter, int* count);
	extern TextSplit

	; Append text at specific position and move cursor!
	; void TextAppend(char* text, const char* append, int* position);
	extern TextAppend

	; Find first text occurrence within a string
	; int TextFindIndex(const char* text, const char* find);
	extern TextFindIndex

	; Get upper case version of provided string
	; const char* TextToUpper(const char* text);
	extern TextToUpper

	; Get lower case version of provided string
	; const char* TextToLower(const char* text);
	extern TextToLower

	; Get Pascal case notation version of provided string
	; const char* TextToPascal(const char* text);
	extern TextToPascal

	; Get Snake case notation version of provided string
	; const char* TextToSnake(const char* text);
	extern TextToSnake

	; Get Camel case notation version of provided string
	; const char* TextToCamel(const char* text);
	extern TextToCamel

	; Get integer value from text (negative values not supported)
	; int TextToInteger(const char* text);
	extern TextToInteger

	; Get float value from text (negative values not supported)
	; float TextToFloat(const char* text);
	extern TextToFloat

%endif ; RTEXT_INC
