%ifndef RMODELS_INC
%define RMODELS_INC

; Basic geometric 3D shapes drawing functions

	; Draw a line in 3D world space
	; void DrawLine3D(Vector3 startPos, Vector3 endPos, Color color);
	extern DrawLine3D

	; Draw a point in 3D space, actually a small line
	; void DrawPoint3D(Vector3 position, Color color);
	extern DrawPoint3D

	; Draw a circle in 3D world space
	; void DrawCircle3D(Vector3 center, float radius, Vector3 rotationAxis, float rotationAngle, Color color);
	extern DrawCircle3D

	; Draw a color-filled triangle (vertex in counter-clockwise order!)
	; void DrawTriangle3D(Vector3 v1, Vector3 v2, Vector3 v3, Color color);
	extern DrawTriangle3D

	; Draw a triangle strip defined by points
	; void DrawTriangleStrip3D(const Vector3* points, int pointCount, Color color);
	extern DrawTriangleStrip3D

	; Draw cube
	; void DrawCube(Vector3 position, float width, float height, float length, Color color);
	extern DrawCube

	; Draw cube (Vector version)
	; void DrawCubeV(Vector3 position, Vector3 size, Color color);
	extern DrawCubeV

	; Draw cube wires
	; void DrawCubeWires(Vector3 position, float width, float height, float length, Color color);
	extern DrawCubeWires

	; Draw cube wires (Vector version)
	; void DrawCubeWiresV(Vector3 position, Vector3 size, Color color);
	extern DrawCubeWiresV

	; Draw sphere
	; void DrawSphere(Vector3 centerPos, float radius, Color color);
	extern DrawSphere

	; Draw sphere with extended parameters
	; void DrawSphereEx(Vector3 centerPos, float radius, int rings, int slices, Color color);
	extern DrawSphereEx

	; Draw sphere wires
	; void DrawSphereWires(Vector3 centerPos, float radius, int rings, int slices, Color color);
	extern DrawSphereWires

	; Draw a cylinder/cone
	; void DrawCylinder(Vector3 position, float radiusTop, float radiusBottom, float height, int slices, Color color);
	extern DrawCylinder

	; Draw a cylinder with base at startPos and top at endPos
	; void DrawCylinderEx(Vector3 startPos, Vector3 endPos, float startRadius, float endRadius, int sides, Color color);
	extern DrawCylinderEx

	; Draw a cylinder/cone wires
	; void DrawCylinderWires(Vector3 position, float radiusTop, float radiusBottom, float height, int slices, Color color);
	extern DrawCylinderWires

	; Draw a cylinder wires with base at startPos and top at endPos
	; void DrawCylinderWiresEx(Vector3 startPos, Vector3 endPos, float startRadius, float endRadius, int sides, Color color);
	extern DrawCylinderWiresEx

	; Draw a capsule with the center of its sphere caps at startPos and endPos
	; void DrawCapsule(Vector3 startPos, Vector3 endPos, float radius, int slices, int rings, Color color);
	extern DrawCapsule

	; Draw capsule wireframe with the center of its sphere caps at startPos and endPos
	; void DrawCapsuleWires(Vector3 startPos, Vector3 endPos, float radius, int slices, int rings, Color color);
	extern DrawCapsuleWires

	; Draw a plane XZ
	; void DrawPlane(Vector3 centerPos, Vector2 size, Color color);
	extern DrawPlane

	; Draw a ray line
	; void DrawRay(Ray ray, Color color);
	extern DrawRay

	; Draw a grid (centered at (0, 0, 0))
	; void DrawGrid(int slices, float spacing);
	extern DrawGrid

;------------------------------------------------------------------------------------
; Model 3d Loading and Drawing Functions (Module: models)
;------------------------------------------------------------------------------------

	; Model management functions

		; Load model from files (meshes and materials)
		; Model LoadModel(const char* fileName);
		extern LoadModel

		; Load model from generated mesh (default material)
		; Model LoadModelFromMesh(Mesh mesh);
		extern LoadModelFromMesh

		; Check if a model is valid (loaded in GPU, VAO/VBOs)
		; bool IsModelValid(Model model);
		extern IsModelValid

		; Unload model (including meshes) from memory (RAM and/or VRAM)
		; void UnloadModel(Model model);
		extern UnloadModel

		; Compute model bounding box limits (considers all meshes)
		; BoundingBox GetModelBoundingBox(Model model);
		extern GetModelBoundingBox

	; Model drawing functions

		; Draw a model (with texture if set)
		; void DrawModel(Model model, Vector3 position, float scale, Color tint);
		extern DrawModel

		; Draw a model with extended parameters
		; void DrawModelEx(Model model, Vector3 position, Vector3 rotationAxis, float rotationAngle, Vector3 scale, Color tint);
		extern DrawModelEx

		; Draw a model wires (with texture if set)
		; void DrawModelWires(Model model, Vector3 position, float scale, Color tint);
		extern DrawModelWires

		; Draw a model wires (with texture if set) with extended parameters
		; void DrawModelWiresEx(Model model, Vector3 position, Vector3 rotationAxis, float rotationAngle, Vector3 scale, Color tint);
		extern DrawModelWiresEx

		; Draw a model as points
		; void DrawModelPoints(Model model, Vector3 position, float scale, Color tint);
		extern DrawModelPoints

		; Draw a model as points with extended parameters
		; void DrawModelPointsEx(Model model, Vector3 position, Vector3 rotationAxis, float rotationAngle, Vector3 scale, Color tint);
		extern DrawModelPointsEx

		; Draw bounding box (wires)
		; void DrawBoundingBox(BoundingBox box, Color color);
		extern DrawBoundingBox

		; Draw a billboard texture
		; void DrawBillboard(Camera camera, Texture2D texture, Vector3 position, float scale, Color tint);
		extern DrawBillboard

		; Draw a billboard texture defined by source
		; void DrawBillboardRec(Camera camera, Texture2D texture, Rectangle source, Vector3 position, Vector2 size, Color tint);
		extern DrawBillboardRec

		; Draw a billboard texture defined by source and rotation
		; void DrawBillboardPro(Camera camera, Texture2D texture, Rectangle source, Vector3 position, Vector3 up, Vector2 size, Vector2 origin, float rotation, Color tint);
		extern DrawBillboardPro

	; Mesh management functions

		; Upload mesh vertex data in GPU and provide VAO/VBO ids
		; void UploadMesh(Mesh* mesh, bool dynamic);
		extern UploadMesh

		; Update mesh vertex data in GPU for a specific buffer index
		; void UpdateMeshBuffer(Mesh mesh, int index, const void* data, int dataSize, int offset);
		extern UpdateMeshBuffer

		; Unload mesh data from CPU and GPU
		; void UnloadMesh(Mesh mesh);
		extern UnloadMesh

		; Draw a 3d mesh with material and transform
		; void DrawMesh(Mesh mesh, Material material, Matrix transform);
		extern DrawMesh

		; Draw multiple mesh instances with material and different transforms
		; void DrawMeshInstanced(Mesh mesh, Material material, const Matrix* transforms, int instances);
		extern DrawMeshInstanced

		; Compute mesh bounding box limits
		; BoundingBox GetMeshBoundingBox(Mesh mesh);
		extern GetMeshBoundingBox

		; Compute mesh tangents
		; void GenMeshTangents(Mesh* mesh);
		extern GenMeshTangents

		; Export mesh data to file, returns true on success
		; bool ExportMesh(Mesh mesh, const char* fileName);
		extern ExportMesh

		; Export mesh as code file (.h) defining multiple arrays of vertex attributes
		; bool ExportMeshAsCode(Mesh mesh, const char* fileName);
		extern ExportMeshAsCode

	; Mesh generation functions

		; Generate polygonal mesh
		; Mesh GenMeshPoly(int sides, float radius);
		extern GenMeshPoly

		; Generate plane mesh (with subdivisions)
		; Mesh GenMeshPlane(float width, float length, int resX, int resZ);
		extern GenMeshPlane

		; Generate cuboid mesh
		; Mesh GenMeshCube(float width, float height, float length);
		extern GenMeshCube

		; Generate sphere mesh (standard sphere)
		; Mesh GenMeshSphere(float radius, int rings, int slices);
		extern GenMeshSphere

		; Generate half-sphere mesh (no bottom cap)
		; Mesh GenMeshHemiSphere(float radius, int rings, int slices);
		extern GenMeshHemiSphere

		; Generate cylinder mesh
		; Mesh GenMeshCylinder(float radius, float height, int slices);
		extern GenMeshCylinder

		; Generate cone/pyramid mesh
		; Mesh GenMeshCone(float radius, float height, int slices);
		extern GenMeshCone

		; Generate torus mesh
		; Mesh GenMeshTorus(float radius, float size, int radSeg, int sides);
		extern GenMeshTorus

		; Generate trefoil knot mesh
		; Mesh GenMeshKnot(float radius, float size, int radSeg, int sides);
		extern GenMeshKnot

		; Generate heightmap mesh from image data
		; Mesh GenMeshHeightmap(Image heightmap, Vector3 size);
		extern GenMeshHeightmap

		; Generate cubes-based map mesh from image data
		; Mesh GenMeshCubicmap(Image cubicmap, Vector3 cubeSize);
		extern GenMeshCubicmap

	; Material loading/unloading functions

		; Load materials from model file
		; Material* LoadMaterials(const char* fileName, int* materialCount);
		extern LoadMaterials

		; Load default material (Supports: DIFFUSE, SPECULAR, NORMAL maps)
		; Material LoadMaterialDefault(void);
		extern LoadMaterialDefault

		; Check if a material is valid (shader assigned, map textures loaded in GPU)
		; bool IsMaterialValid(Material material);
		extern IsMaterialValid

		; Unload material from GPU memory (VRAM)
		; void UnloadMaterial(Material material);
		extern UnloadMaterial

		; Set texture for a material map type (MATERIAL_MAP_DIFFUSE, MATERIAL_MAP_SPECULAR...)
		; void SetMaterialTexture(Material* material, int mapType, Texture2D texture);
		extern SetMaterialTexture

		; Set material for a mesh
		; void SetModelMeshMaterial(Model* model, int meshId, int materialId);
		extern SetModelMeshMaterial

	; Model animations loading/unloading functions

		; Load model animations from file
		; ModelAnimation* LoadModelAnimations(const char* fileName, int* animCount);
		extern LoadModelAnimations

		; Update model animation pose (CPU)
		; void UpdateModelAnimation(Model model, ModelAnimation anim, int frame);
		extern UpdateModelAnimation

		; Update model animation mesh bone matrices (GPU skinning)
		; void UpdateModelAnimationBones(Model model, ModelAnimation anim, int frame);
		extern UpdateModelAnimationBones

		; Unload animation data
		; void UnloadModelAnimation(ModelAnimation anim);
		extern UnloadModelAnimation

		; Unload animation array data
		; void UnloadModelAnimations(ModelAnimation* animations, int animCount);
		extern UnloadModelAnimations

		; Check model animation skeleton match
		; bool IsModelAnimationValid(Model model, ModelAnimation anim);
		extern IsModelAnimationValid

; Collision detection functions

	; Check collision between two spheres
	; bool CheckCollisionSpheres(Vector3 center1, float radius1, Vector3 center2, float radius2);
	extern CheckCollisionSpheres

	; Check collision between two bounding boxes
	; bool CheckCollisionBoxes(BoundingBox box1, BoundingBox box2);
	extern CheckCollisionBoxes

	; Check collision between box and sphere
	; bool CheckCollisionBoxSphere(BoundingBox box, Vector3 center, float radius);
	extern CheckCollisionBoxSphere

	; Get collision info between ray and sphere
	; RayCollision GetRayCollisionSphere(Ray ray, Vector3 center, float radius);
	extern GetRayCollisionSphere

	; Get collision info between ray and box
	; RayCollision GetRayCollisionBox(Ray ray, BoundingBox box);
	extern GetRayCollisionBox

	; Get collision info between ray and mesh
	; RayCollision GetRayCollisionMesh(Ray ray, Mesh mesh, Matrix transform);
	extern GetRayCollisionMesh

	; Get collision info between ray and triangle
	; RayCollision GetRayCollisionTriangle(Ray ray, Vector3 p1, Vector3 p2, Vector3 p3);
	extern GetRayCollisionTriangle

	; Get collision info between ray and quad
	; RayCollision GetRayCollisionQuad(Ray ray, Vector3 p1, Vector3 p2, Vector3 p3, Vector3 p4);
	extern GetRayCollisionQuad

%endif ; RMODELS_INC
