%ifndef RSHAPES_INC
%define RSHAPES_INC

; Set texture and rectangle to be used on shapes drawing
; NOTE: It can be useful when using basic shapes and one single font,
; defining a font char white rectangle would allow drawing everything in a single draw call

	; Set texture and rectangle to be used on shapes drawing
	; void SetShapesTexture(Texture2D texture, Rectangle source);
	extern SetShapesTexture

	; Get texture that is used for shapes drawing
	; Texture2D GetShapesTexture(void);
	extern GetShapesTexture

	; Get texture source rectangle that is used for shapes drawing
	; Rectangle GetShapesTextureRectangle(void);
	extern GetShapesTextureRectangle

; Basic shapes drawing functions

	; Draw a pixel using geometry [Can be slow, use with care]
	; void DrawPixel(int posX, int posY, Color color);
	extern DrawPixel

	; Draw a pixel using geometry (Vector version) [Can be slow, use with care]
	; void DrawPixelV(Vector2 position, Color color);
	extern DrawPixelV

	; Draw a line
	; void DrawLine(int startPosX, int startPosY, int endPosX, int endPosY, Color color);
	extern DrawLine

	; Draw a line (using gl lines)
	; void DrawLineV(Vector2 startPos, Vector2 endPos, Color color);
	extern DrawLineV

	; Draw a line (using triangles/quads)
	; void DrawLineEx(Vector2 startPos, Vector2 endPos, float thick, Color color);
	extern DrawLineEx

	; Draw lines sequence (using gl lines)
	; void DrawLineStrip(const Vector2* points, int pointCount, Color color);
	extern DrawLineStrip

	; Draw line segment cubic-bezier in-out interpolation
	; void DrawLineBezier(Vector2 startPos, Vector2 endPos, float thick, Color color);
	extern DrawLineBezier

	; Draw a color-filled circle
	; void DrawCircle(int centerX, int centerY, float radius, Color color);
	extern DrawCircle

	; Draw a piece of a circle
	; void DrawCircleSector(Vector2 center, float radius, float startAngle, float endAngle, int segments, Color color);
	extern DrawCircleSector

	; Draw circle sector outline
	; void DrawCircleSectorLines(Vector2 center, float radius, float startAngle, float endAngle, int segments, Color color);
	extern DrawCircleSectorLines

	; Draw a gradient-filled circle
	; void DrawCircleGradient(int centerX, int centerY, float radius, Color inner, Color outer);
	extern DrawCircleGradient

	; Draw a color-filled circle (Vector version)
	; void DrawCircleV(Vector2 center, float radius, Color color);
	extern DrawCircleV

	; Draw circle outline
	; void DrawCircleLines(int centerX, int centerY, float radius, Color color);
	extern DrawCircleLines

	; Draw circle outline (Vector version)
	; void DrawCircleLinesV(Vector2 center, float radius, Color color);
	extern DrawCircleLinesV

	; Draw ellipse
	; void DrawEllipse(int centerX, int centerY, float radiusH, float radiusV, Color color);
	extern DrawEllipse

	; Draw ellipse outline
	; void DrawEllipseLines(int centerX, int centerY, float radiusH, float radiusV, Color color);
	extern DrawEllipseLines

	; Draw ring
	; void DrawRing(Vector2 center, float innerRadius, float outerRadius, float startAngle, float endAngle, int segments, Color color);
	extern DrawRing

	; Draw ring outline
	; void DrawRingLines(Vector2 center, float innerRadius, float outerRadius, float startAngle, float endAngle, int segments, Color color);
	extern DrawRingLines

	; Draw a color-filled rectangle
	; void DrawRectangle(int posX, int posY, int width, int height, Color color);
	extern DrawRectangle

	; Draw a color-filled rectangle (Vector version)
	; void DrawRectangleV(Vector2 position, Vector2 size, Color color);
	extern DrawRectangleV

	; Draw a color-filled rectangle
	; void DrawRectangleRec(Rectangle rec, Color color);
	extern DrawRectangleRec

	; Draw a color-filled rectangle with pro parameters
	; void DrawRectanglePro(Rectangle rec, Vector2 origin, float rotation, Color color);
	extern DrawRectanglePro

	; Draw a vertical-gradient-filled rectangle
	; void DrawRectangleGradientV(int posX, int posY, int width, int height, Color top, Color bottom);
	extern DrawRectangleGradientV

	; Draw a horizontal-gradient-filled rectangle
	; void DrawRectangleGradientH(int posX, int posY, int width, int height, Color left, Color right);
	extern DrawRectangleGradientH

	; Draw a gradient-filled rectangle with custom vertex colors
	; void DrawRectangleGradientEx(Rectangle rec, Color topLeft, Color bottomLeft, Color topRight, Color bottomRight);
	extern DrawRectangleGradientEx

	; Draw rectangle outline
	; void DrawRectangleLines(int posX, int posY, int width, int height, Color color);
	extern DrawRectangleLines

	; Draw rectangle outline with extended parameters
	; void DrawRectangleLinesEx(Rectangle rec, float lineThick, Color color);
	extern DrawRectangleLinesEx

	; Draw rectangle with rounded edges
	; void DrawRectangleRounded(Rectangle rec, float roundness, int segments, Color color);
	extern DrawRectangleRounded

	; Draw rectangle lines with rounded edges
	; void DrawRectangleRoundedLines(Rectangle rec, float roundness, int segments, Color color);
	extern DrawRectangleRoundedLines

	; Draw rectangle with rounded edges outline
	; void DrawRectangleRoundedLinesEx(Rectangle rec, float roundness, int segments, float lineThick, Color color);
	extern DrawRectangleRoundedLinesEx

	; Draw a color-filled triangle (vertex in counter-clockwise order!)
	; void DrawTriangle(Vector2 v1, Vector2 v2, Vector2 v3, Color color);
	extern DrawTriangle

	; Draw triangle outline (vertex in counter-clockwise order!)
	; void DrawTriangleLines(Vector2 v1, Vector2 v2, Vector2 v3, Color color);
	extern DrawTriangleLines

	; Draw a triangle fan defined by points (first vertex is the center)
	; void DrawTriangleFan(const Vector2* points, int pointCount, Color color);
	extern DrawTriangleFan

	; Draw a triangle strip defined by points
	; void DrawTriangleStrip(const Vector2* points, int pointCount, Color color);
	extern DrawTriangleStrip

	; Draw a regular polygon (Vector version)
	; void DrawPoly(Vector2 center, int sides, float radius, float rotation, Color color);
	extern DrawPoly

	; Draw a polygon outline of n sides
	; void DrawPolyLines(Vector2 center, int sides, float radius, float rotation, Color color);
	extern DrawPolyLines

	; Draw a polygon outline of n sides with extended parameters
	; void DrawPolyLinesEx(Vector2 center, int sides, float radius, float rotation, float lineThick, Color color);
	extern DrawPolyLinesEx

; Splines drawing functions

	; Draw spline: Linear, minimum 2 points
	; void DrawSplineLinear(const Vector2* points, int pointCount, float thick, Color color);
	extern DrawSplineLinear

	; Draw spline: B-Spline, minimum 4 points
	; void DrawSplineBasis(const Vector2* points, int pointCount, float thick, Color color);
	extern DrawSplineBasis

	; Draw spline: Catmull-Rom, minimum 4 points
	; void DrawSplineCatmullRom(const Vector2* points, int pointCount, float thick, Color color);
	extern DrawSplineCatmullRom

	; Draw spline: Quadratic Bezier, minimum 3 points (1 control point): [p1, c2, p3, c4...]
	; void DrawSplineBezierQuadratic(const Vector2* points, int pointCount, float thick, Color color);
	extern DrawSplineBezierQuadratic

	; Draw spline: Cubic Bezier, minimum 4 points (2 control points): [p1, c2, c3, p4, c5, c6...]
	; void DrawSplineBezierCubic(const Vector2* points, int pointCount, float thick, Color color);
	extern DrawSplineBezierCubic

	; Draw spline segment: Linear, 2 points
	; void DrawSplineSegmentLinear(Vector2 p1, Vector2 p2, float thick, Color color);
	extern DrawSplineSegmentLinear

	; Draw spline segment: B-Spline, 4 points
	; void DrawSplineSegmentBasis(Vector2 p1, Vector2 p2, Vector2 p3, Vector2 p4, float thick, Color color);
	extern DrawSplineSegmentBasis

	; Draw spline segment: Catmull-Rom, 4 points
	; void DrawSplineSegmentCatmullRom(Vector2 p1, Vector2 p2, Vector2 p3, Vector2 p4, float thick, Color color);
	extern DrawSplineSegmentCatmullRom

	; Draw spline segment: Quadratic Bezier, 2 points, 1 control point
	; void DrawSplineSegmentBezierQuadratic(Vector2 p1, Vector2 c2, Vector2 p3, float thick, Color color);
	extern DrawSplineSegmentBezierQuadratic

	; Draw spline segment: Cubic Bezier, 2 points, 2 control points
	; void DrawSplineSegmentBezierCubic(Vector2 p1, Vector2 c2, Vector2 c3, Vector2 p4, float thick, Color color);
	extern DrawSplineSegmentBezierCubic

; Spline segment point evaluation functions, for a given t [0.0f .. 1.0f]

	; Get (evaluate) spline point: Linear
	; Vector2 GetSplinePointLinear(Vector2 startPos, Vector2 endPos, float t);
	extern GetSplinePointLinear

	; Get (evaluate) spline point: B-Spline
	; Vector2 GetSplinePointBasis(Vector2 p1, Vector2 p2, Vector2 p3, Vector2 p4, float t);
	extern GetSplinePointBasis

	; Get (evaluate) spline point: Catmull-Rom
	; Vector2 GetSplinePointCatmullRom(Vector2 p1, Vector2 p2, Vector2 p3, Vector2 p4, float t);
	extern GetSplinePointCatmullRom

	; Get (evaluate) spline point: Quadratic Bezier
	; Vector2 GetSplinePointBezierQuad(Vector2 p1, Vector2 c2, Vector2 p3, float t);
	extern GetSplinePointBezierQuad

	; Get (evaluate) spline point: Cubic Bezier
	; Vector2 GetSplinePointBezierCubic(Vector2 p1, Vector2 c2, Vector2 c3, Vector2 p4, float t);
	extern GetSplinePointBezierCubic

; Basic shapes collision detection functions

	; Check collision between two rectangles
	; bool CheckCollisionRecs(Rectangle rec1, Rectangle rec2);
	extern CheckCollisionRecs

	; Check collision between two circles
	; bool CheckCollisionCircles(Vector2 center1, float radius1, Vector2 center2, float radius2);
	extern CheckCollisionCircles

	; Check collision between circle and rectangle
	; bool CheckCollisionCircleRec(Vector2 center, float radius, Rectangle rec);
	extern CheckCollisionCircleRec

	; Check if circle collides with a line created betweeen two points [p1] and [p2]
	; bool CheckCollisionCircleLine(Vector2 center, float radius, Vector2 p1, Vector2 p2);
	extern CheckCollisionCircleLine

	; Check if point is inside rectangle
	; bool CheckCollisionPointRec(Vector2 point, Rectangle rec);
	extern CheckCollisionPointRec

	; Check if point is inside circle
	; bool CheckCollisionPointCircle(Vector2 point, Vector2 center, float radius);
	extern CheckCollisionPointCircle

	; Check if point is inside a triangle
	; bool CheckCollisionPointTriangle(Vector2 point, Vector2 p1, Vector2 p2, Vector2 p3);
	extern CheckCollisionPointTriangle

	; Check if point belongs to line created between two points [p1] and [p2] with defined margin in pixels [threshold]
	; bool CheckCollisionPointLine(Vector2 point, Vector2 p1, Vector2 p2, int threshold);
	extern CheckCollisionPointLine

	; Check if point is within a polygon described by array of vertices
	; bool CheckCollisionPointPoly(Vector2 point, const Vector2* points, int pointCount);
	extern CheckCollisionPointPoly

	; Check the collision between two lines defined by two points each, returns collision point by reference
	; bool CheckCollisionLines(Vector2 startPos1, Vector2 endPos1, Vector2 startPos2, Vector2 endPos2, Vector2* collisionPoint);
	extern CheckCollisionLines

	; Get collision rectangle for two rectangles collision
	; Rectangle GetCollisionRec(Rectangle rec1, Rectangle rec2);
	extern GetCollisionRec

%endif ; RSHAPES_INC
