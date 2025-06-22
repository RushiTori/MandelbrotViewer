%ifndef RAYMATH_INC
%define RAYMATH_INC

; Utils math

    ; Clamp float value
	; float Clamp(float value, float min, float max);
	extern Clamp

    ; Calculate linear interpolation between two floats
	; float Lerp(float start, float end, float amount);
	extern Lerp

    ; Normalize input value within input range
	; float Normalize(float value, float start, float end);
	extern Normalize

    ; Remap input value within input range to output range
	; float Remap(float value, float inputStart, float inputEnd, float outputStart, float outputEnd);
	extern Remap

    ; Wrap input value from min to max
	; float Wrap(float value, float min, float max);
	extern Wrap

    ; Check whether two given floats are almost equal
	; int FloatEquals(float x, float y);
	extern FloatEquals

; Vector2 math

    ; Vector with components value 0.0f
	; Vector2 Vector2Zero(void);
	extern Vector2Zero

    ; Vector with components value 1.0f
	; Vector2 Vector2One(void);
	extern Vector2One

    ; Add two vectors (v1 + v2)
	; Vector2 Vector2Add(Vector2 v1, Vector2 v2);
	extern Vector2Add

    ; Add vector and float value
	; Vector2 Vector2AddValue(Vector2 v, float add);
	extern Vector2AddValue

    ; Subtract two vectors (v1 - v2)
	; Vector2 Vector2Subtract(Vector2 v1, Vector2 v2);
	extern Vector2Subtract

    ; Subtract vector by float value
	; Vector2 Vector2SubtractValue(Vector2 v, float sub);
	extern Vector2SubtractValue

    ; Calculate vector length
	; float Vector2Length(Vector2 v);
	extern Vector2Length

    ; Calculate vector square length
	; float Vector2LengthSqr(Vector2 v);
	extern Vector2LengthSqr

    ; Calculate two vectors dot product
	; float Vector2DotProduct(Vector2 v1, Vector2 v2);
	extern Vector2DotProduct

    ; Calculate distance between two vectors
	; float Vector2Distance(Vector2 v1, Vector2 v2);
	extern Vector2Distance

    ; Calculate square distance between two vectors
	; float Vector2DistanceSqr(Vector2 v1, Vector2 v2);
	extern Vector2DistanceSqr

    ; Calculate angle from two vectors
	; float Vector2Angle(Vector2 v1, Vector2 v2);
	extern Vector2Angle

    ; Scale vector (multiply by value)
	; Vector2 Vector2Scale(Vector2 v, float scale);
	extern Vector2Scale

    ; Multiply vector by vector
	; Vector2 Vector2Multiply(Vector2 v1, Vector2 v2);
	extern Vector2Multiply

    ; Negate vector
	; Vector2 Vector2Negate(Vector2 v);
	extern Vector2Negate

    ; Divide vector by vector
	; Vector2 Vector2Divide(Vector2 v1, Vector2 v2);
	extern Vector2Divide

    ; Normalize provided vector
	; Vector2 Vector2Normalize(Vector2 v);
	extern Vector2Normalize

    ; Transforms a Vector2 by a given Matrix
	; Vector2 Vector2Transform(Vector2 v, Matrix mat);
	extern Vector2Transform

    ; Calculate linear interpolation between two vectors
	; Vector2 Vector2Lerp(Vector2 v1, Vector2 v2, float amount);
	extern Vector2Lerp

    ; Calculate reflected vector to normal
	; Vector2 Vector2Reflect(Vector2 v, Vector2 normal);
	extern Vector2Reflect

    ; Rotate vector by angle
	; Vector2 Vector2Rotate(Vector2 v, float angle);
	extern Vector2Rotate

    ; Move Vector towards target
	; Vector2 Vector2MoveTowards(Vector2 v, Vector2 target, float maxDistance);
	extern Vector2MoveTowards

    ; Invert the given vector
	; Vector2 Vector2Invert(Vector2 v);
	extern Vector2Invert

    ; Clamp the components of the vector between min and max values specified by the given vectors
	; Vector2 Vector2Clamp(Vector2 v, Vector2 min, Vector2 max);
	extern Vector2Clamp

    ; Clamp the magnitude of the vector between two min and max values
	; Vector2 Vector2ClampValue(Vector2 v, float min, float max);
	extern Vector2ClampValue

    ; Check whether two given vectors are almost equal
	; int Vector2Equals(Vector2 p, Vector2 q);
	extern Vector2Equals

; Vector3 math

    ; Vector with components value 0.0f
	; Vector3 Vector3Zero(void);
	extern Vector3Zero

    ; Vector with components value 1.0f
	; Vector3 Vector3One(void);
	extern Vector3One

    ; Add two vectors
	; Vector3 Vector3Add(Vector3 v1, Vector3 v2);
	extern Vector3Add

    ; Add vector and float value
	; Vector3 Vector3AddValue(Vector3 v, float add);
	extern Vector3AddValue

    ; Subtract two vectors
	; Vector3 Vector3Subtract(Vector3 v1, Vector3 v2);
	extern Vector3Subtract

    ; Subtract vector by float value
	; Vector3 Vector3SubtractValue(Vector3 v, float sub);
	extern Vector3SubtractValue

    ; Multiply vector by scalar
	; Vector3 Vector3Scale(Vector3 v, float scalar);
	extern Vector3Scale

    ; Multiply vector by vector
	; Vector3 Vector3Multiply(Vector3 v1, Vector3 v2);
	extern Vector3Multiply

    ; Calculate two vectors cross product
	; Vector3 Vector3CrossProduct(Vector3 v1, Vector3 v2);
	extern Vector3CrossProduct

    ; Calculate one vector perpendicular vector
	; Vector3 Vector3Perpendicular(Vector3 v);
	extern Vector3Perpendicular

    ; Calculate vector length
	; float Vector3Length(const Vector3 v);
	extern Vector3Length

    ; Calculate vector square length
	; float Vector3LengthSqr(const Vector3 v);
	extern Vector3LengthSqr

    ; Calculate two vectors dot product
	; float Vector3DotProduct(Vector3 v1, Vector3 v2);
	extern Vector3DotProduct

    ; Calculate distance between two vectors
	; float Vector3Distance(Vector3 v1, Vector3 v2);
	extern Vector3Distance

    ; Calculate square distance between two vectors
	; float Vector3DistanceSqr(Vector3 v1, Vector3 v2);
	extern Vector3DistanceSqr

    ; Calculate angle between two vectors
	; float Vector3Angle(Vector3 v1, Vector3 v2);
	extern Vector3Angle

    ; Negate provided vector (invert direction)
	; Vector3 Vector3Negate(Vector3 v);
	extern Vector3Negate

    ; Divide vector by vector
	; Vector3 Vector3Divide(Vector3 v1, Vector3 v2);
	extern Vector3Divide

    ; Normalize provided vector
	; Vector3 Vector3Normalize(Vector3 v);
	extern Vector3Normalize

    ; Orthonormalize provided vectors Makes vectors normalized and orthogonal to each other Gram-Schmidt function implementation
	; void Vector3OrthoNormalize(Vector3 *v1, Vector3 *v2);
	extern Vector3OrthoNormalize

    ; Transforms a Vector3 by a given Matrix
	; Vector3 Vector3Transform(Vector3 v, Matrix mat);
	extern Vector3Transform

    ; Transform a vector by quaternion rotation
	; Vector3 Vector3RotateByQuaternion(Vector3 v, Quaternion q);
	extern Vector3RotateByQuaternion

    ; Rotates a vector around an axis
	; Vector3 Vector3RotateByAxisAngle(Vector3 v, Vector3 axis, float angle);
	extern Vector3RotateByAxisAngle

    ; Calculate linear interpolation between two vectors
	; Vector3 Vector3Lerp(Vector3 v1, Vector3 v2, float amount);
	extern Vector3Lerp

    ; Calculate reflected vector to normal
	; Vector3 Vector3Reflect(Vector3 v, Vector3 normal);
	extern Vector3Reflect

    ; Get min value for each pair of components
	; Vector3 Vector3Min(Vector3 v1, Vector3 v2);
	extern Vector3Min

    ; Get max value for each pair of components
	; Vector3 Vector3Max(Vector3 v1, Vector3 v2);
	extern Vector3Max

    ; Compute barycenter coordinates (u, v, w) for point p with respect to triangle (a, b, c) NOTE: Assumes P is on the plane of the triangle
	; Vector3 Vector3Barycenter(Vector3 p, Vector3 a, Vector3 b, Vector3 c);
	extern Vector3Barycenter

    ; Projects a Vector3 from screen space into object space NOTE: We are avoiding calling other raymath functions despite available
	; Vector3 Vector3Unproject(Vector3 source, Matrix projection, Matrix view);
	extern Vector3Unproject

    ; Get Vector3 as float array
	; float3 Vector3ToFloatV(Vector3 v);
	extern Vector3ToFloatV

    ; Invert the given vector
	; Vector3 Vector3Invert(Vector3 v);
	extern Vector3Invert

    ; Clamp the components of the vector between min and max values specified by the given vectors
	; Vector3 Vector3Clamp(Vector3 v, Vector3 min, Vector3 max);
	extern Vector3Clamp

    ; Clamp the magnitude of the vector between two values
	; Vector3 Vector3ClampValue(Vector3 v, float min, float max);
	extern Vector3ClampValue

    ; Check whether two given vectors are almost equal
	; int Vector3Equals(Vector3 p, Vector3 q);
	extern Vector3Equals

    ; Compute the direction of a refracted ray where v specifies the normalized direction of the incoming ray, n specifies the normalized normal vector of the interface of two optical media, and r specifies the ratio of the refractive index of the medium from where the ray comes to the refractive index of the medium on the other side of the surface
	; Vector3 Vector3Refract(Vector3 v, Vector3 n, float r);
	extern Vector3Refract

; Matrix math

    ; Compute matrix determinant
	; float MatrixDeterminant(Matrix mat);
	extern MatrixDeterminant

    ; Get the trace of the matrix (sum of the values along the diagonal)
	; float MatrixTrace(Matrix mat);
	extern MatrixTrace

    ; Transposes provided matrix
	; Matrix MatrixTranspose(Matrix mat);
	extern MatrixTranspose

    ; Invert provided matrix
	; Matrix MatrixInvert(Matrix mat);
	extern MatrixInvert

    ; Get identity matrix
	; Matrix MatrixIdentity(void);
	extern MatrixIdentity

    ; Add two matrices
	; Matrix MatrixAdd(Matrix left, Matrix right);
	extern MatrixAdd

    ; Subtract two matrices (left - right)
	; Matrix MatrixSubtract(Matrix left, Matrix right);
	extern MatrixSubtract

    ; Get two matrix multiplication NOTE: When multiplying matrices... the order matters!
	; Matrix MatrixMultiply(Matrix left, Matrix right);
	extern MatrixMultiply

    ; Get translation matrix
	; Matrix MatrixTranslate(float x, float y, float z);
	extern MatrixTranslate

    ; Create rotation matrix from axis and angle NOTE: Angle should be provided in radians
	; Matrix MatrixRotate(Vector3 axis, float angle);
	extern MatrixRotate

    ; Get x-rotation matrix NOTE: Angle must be provided in radians
	; Matrix MatrixRotateX(float angle);
	extern MatrixRotateX

    ; Get y-rotation matrix NOTE: Angle must be provided in radians
	; Matrix MatrixRotateY(float angle);
	extern MatrixRotateY

    ; Get z-rotation matrix NOTE: Angle must be provided in radians
	; Matrix MatrixRotateZ(float angle);
	extern MatrixRotateZ

    ; Get xyz-rotation matrix NOTE: Angle must be provided in radians
	; Matrix MatrixRotateXYZ(Vector3 angle);
	extern MatrixRotateXYZ

    ; Get zyx-rotation matrix NOTE: Angle must be provided in radians
	; Matrix MatrixRotateZYX(Vector3 angle);
	extern MatrixRotateZYX

    ; Get scaling matrix
	; Matrix MatrixScale(float x, float y, float z);
	extern MatrixScale

    ; Get perspective projection matrix
	; Matrix MatrixFrustum(double left, double right, double bottom, double top, double near, double far);
	extern MatrixFrustum

    ; Get perspective projection matrix NOTE: Fovy angle must be provided in radians
	; Matrix MatrixPerspective(double fovy, double aspect, double near, double far);
	extern MatrixPerspective

    ; Get orthographic projection matrix
	; Matrix MatrixOrtho(double left, double right, double bottom, double top, double near, double far);
	extern MatrixOrtho

    ; Get camera look-at matrix (view matrix)
	; Matrix MatrixLookAt(Vector3 eye, Vector3 target, Vector3 up);
	extern MatrixLookAt

    ; Get float array of matrix data
	; float16 MatrixToFloatV(Matrix mat);
	extern MatrixToFloatV

; Quaternion math

    ; Add two quaternions
	; Quaternion QuaternionAdd(Quaternion q1, Quaternion q2);
	extern QuaternionAdd

    ; Add quaternion and float value
	; Quaternion QuaternionAddValue(Quaternion q, float add);
	extern QuaternionAddValue

    ; Subtract two quaternions
	; Quaternion QuaternionSubtract(Quaternion q1, Quaternion q2);
	extern QuaternionSubtract

    ; Subtract quaternion and float value
	; Quaternion QuaternionSubtractValue(Quaternion q, float sub);
	extern QuaternionSubtractValue

    ; Get identity quaternion
	; Quaternion QuaternionIdentity(void);
	extern QuaternionIdentity

    ; Computes the length of a quaternion
	; float QuaternionLength(Quaternion q);
	extern QuaternionLength

    ; Normalize provided quaternion
	; Quaternion QuaternionNormalize(Quaternion q);
	extern QuaternionNormalize

    ; Invert provided quaternion
	; Quaternion QuaternionInvert(Quaternion q);
	extern QuaternionInvert

    ; Calculate two quaternion multiplication
	; Quaternion QuaternionMultiply(Quaternion q1, Quaternion q2);
	extern QuaternionMultiply

    ; Scale quaternion by float value
	; Quaternion QuaternionScale(Quaternion q, float mul);
	extern QuaternionScale

    ; Divide two quaternions
	; Quaternion QuaternionDivide(Quaternion q1, Quaternion q2);
	extern QuaternionDivide

    ; Calculate linear interpolation between two quaternions
	; Quaternion QuaternionLerp(Quaternion q1, Quaternion q2, float amount);
	extern QuaternionLerp

    ; Calculate slerp-optimized interpolation between two quaternions
	; Quaternion QuaternionNlerp(Quaternion q1, Quaternion q2, float amount);
	extern QuaternionNlerp

    ; Calculates spherical linear interpolation between two quaternions
	; Quaternion QuaternionSlerp(Quaternion q1, Quaternion q2, float amount);
	extern QuaternionSlerp

    ; Calculate quaternion based on the rotation from one vector to another
	; Quaternion QuaternionFromVector3ToVector3(Vector3 from, Vector3 to);
	extern QuaternionFromVector3ToVector3

    ; Get a quaternion for a given rotation matrix
	; Quaternion QuaternionFromMatrix(Matrix mat);
	extern QuaternionFromMatrix

    ; Get a matrix for a given quaternion
	; Matrix QuaternionToMatrix(Quaternion q);
	extern QuaternionToMatrix

    ; Get rotation quaternion for an angle and axis NOTE: Angle must be provided in radians
	; Quaternion QuaternionFromAxisAngle(Vector3 axis, float angle);
	extern QuaternionFromAxisAngle

    ; Get the rotation angle and axis for a given quaternion
	; void QuaternionToAxisAngle(Quaternion q, Vector3 *outAxis, float *outAngle);
	extern QuaternionToAxisAngle

    ; Get the quaternion equivalent to Euler angles NOTE: Rotation order is ZYX
	; Quaternion QuaternionFromEuler(float pitch, float yaw, float roll);
	extern QuaternionFromEuler

    ; Get the Euler angles equivalent to quaternion (roll, pitch, yaw) NOTE: Angles are returned in a Vector3 struct in radians
	; Vector3 QuaternionToEuler(Quaternion q);
	extern QuaternionToEuler

    ; Transform a quaternion given a transformation matrix
	; Quaternion QuaternionTransform(Quaternion q, Matrix mat);
	extern QuaternionTransform

    ; Check whether two given quaternions are almost equal
	; int QuaternionEquals(Quaternion p, Quaternion q);
	extern QuaternionEquals

%endif ; RAYMATH_INC
