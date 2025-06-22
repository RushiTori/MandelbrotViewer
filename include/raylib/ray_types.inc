%ifndef RAY_TYPES_INC
%define RAY_TYPES_INC

%include "stdtypes.inc"

; Types for macros
	define_type(color,   d, dword)
	define_type(vector2, q, qword)

; Color, 4 components, R8G8B8A8 (32bit)
struc Color
	; Color red value
	; unsigned char r;
	struc_member(uint8_t, r, 1)

	; Color green value
	; unsigned char g;
	struc_member(uint8_t, g, 1)

	; Color blue value
	; unsigned char b;
	struc_member(uint8_t, b, 1)

	; Color alpha value
	; unsigned char a;
	struc_member(uint8_t, a, 1)
endstruc

; Vector2, 2 components
struc Vector2
	; Vector x component
	; float x;
	struc_member(float_t, x, 1)

	; Vector y component
	; float y;
	struc_member(float_t, y, 1)
endstruc

; Vector3, 3 components
struc Vector3
	; Vector x component
	; float x;
	struc_member(float_t, x, 1)
  
	; Vector y component
	; float y;
	struc_member(float_t, y, 1)
  
	; Vector z component
	; float z;
	struc_member(float_t, z, 1)
endstruc

; Vector4, 4 components
struc Vector4
	; Vector x component
	; float x;
	struc_member(float_t, x, 1)
  
	; Vector y component
	; float y;
	struc_member(float_t, y, 1)
  
	; Vector z component
	; float z;
	struc_member(float_t, z, 1)
  
	; Vector w component
	; float w;
	struc_member(float_t, w, 1)
endstruc

; Quaternion, 4 components (Vector4 alias)
struc Quaternion
	; Vector x component
	; float x;
	struc_member(float_t, x, 1)
  
	; Vector y component
	; float y;
	struc_member(float_t, y, 1)
  
	; Vector z component
	; float z;
	struc_member(float_t, z, 1)
  
	; Vector w component
	; float w;
	struc_member(float_t, w, 1)
endstruc

; Matrix, 4x4 components, column major, OpenGL style, right-handed
struc Matrix
	; Matrix first row (4 components)

		; first column, first row element
		; float m0;
		struc_member(float_t, m0, 1)
		
		; second column, first row element
		; float m4;
		struc_member(float_t, m4, 1)
		
		; third column, first row element
		; float m8;
		struc_member(float_t, m8, 1)
		
		; fourth column, first row element
		; float m12;
		struc_member(float_t, m12, 1)

	; Matrix second row (4 components)

		; first column, second row element
		; float m1;
		struc_member(float_t, m1, 1)
		
		; second column, second row element
		; float m5;
		struc_member(float_t, m5, 1)
		
		; third column, second row element
		; float m9;
		struc_member(float_t, m9, 1)
		
		; fourth column, second row element
		; float m13;
		struc_member(float_t, m13, 1)

	; Matrix third row (4 components)

		; first column, third row element
		; float m2;
		struc_member(float_t, m2, 1)
		
		; second column, third row element
		; float m6;
		struc_member(float_t, m6, 1)
		
		; third column, third row element
		; float m10;
		struc_member(float_t, m10, 1)
		
		; fourth column, third row element
		; float m14;
		struc_member(float_t, m14, 1)

	; Matrix fourth row (4 components)

		; first column, fourth row element
		; float m3;
		struc_member(float_t, m3, 1)
		
		; second column, fourth row element
		; float m7;
		struc_member(float_t, m7, 1)
		
		; third column, fourth row element
		; float m11;
		struc_member(float_t, m11, 1)

		; fourth column, fourth row element
		; float m15;
		struc_member(float_t, m15, 1)
endstruc

; Rectangle, 4 components
struc Rectangle
	; Rectangle top-left corner position x
	; float x;     
	struc_member(float_t, x, 1)
  
	; Rectangle top-left corner position y
	; float y;     
	struc_member(float_t, y, 1)
  
	; Rectangle width
	; float width; 
	struc_member(float_t, width, 1)
  
	; Rectangle height
	; float height;
	struc_member(float_t, height, 1)
endstruc

; Image, pixel data stored in CPU memory (RAM)
struc Image
	; Image raw data
	; void* data; 
	struc_member(pointer_t, data, 1)
  
	; Image base width
	; int width;  
	struc_member(int_t, width, 1)
  
	; Image base height
	; int height; 
	struc_member(int_t, height, 1)
  
	; Mipmap levels, 1 by default
	; int mipmaps;
	struc_member(int_t, mipmaps, 1)
  
	; Data format (PixelFormat type)
	; int format; 
	struc_member(int_t, format, 1)
endstruc

; Texture, tex data stored in GPU memory (VRAM)
struc Texture
	; OpenGL texture id
	; unsigned int id;
	struc_member(uint32_t, id, 1)
  
	; Texture base width
	; int width;      
	struc_member(int_t, width, 1)
  
	; Texture base height
	; int height;     
	struc_member(int_t, height, 1)
  
	; Mipmap levels, 1 by default
	; int mipmaps;    
	struc_member(int_t, mipmaps, 1)
  
	; Data format (PixelFormat type)
	; int format;     
	struc_member(int_t, format, 1)
endstruc

; Texture2D, same as Texture
struc Texture2D
	; OpenGL texture id
	; unsigned int id;
	struc_member(uint32_t, id, 1)
  
	; Texture base width
	; int width;      
	struc_member(int_t, width, 1)
  
	; Texture base height
	; int height;     
	struc_member(int_t, height, 1)
  
	; Mipmap levels, 1 by default
	; int mipmaps;    
	struc_member(int_t, mipmaps, 1)
  
	; Data format (PixelFormat type)
	; int format;     
	struc_member(int_t, format, 1)
endstruc

; TextureCubemap, same as Texture
struc TextureCubemap
	; OpenGL texture id
	; unsigned int id;
	struc_member(uint32_t, id, 1)
  
	; Texture base width
	; int width;      
	struc_member(int_t, width, 1)
  
	; Texture base height
	; int height;     
	struc_member(int_t, height, 1)
  
	; Mipmap levels, 1 by default
	; int mipmaps;    
	struc_member(int_t, mipmaps, 1)
  
	; Data format (PixelFormat type)
	; int format;     
	struc_member(int_t, format, 1)
endstruc

; RenderTexture, fbo for texture rendering
struc RenderTexture
	; OpenGL framebuffer object id
	; unsigned int id;
	struc_member(uint32_t, id, 1)
  
	; Color buffer attachment texture
	; Texture texture;
		struc_member(uint32_t, texture_id,      1)
		struc_member(int_t,    texture_width,   1)
		struc_member(int_t,    texture_height,  1)
		struc_member(int_t,    texture_mipmaps, 1)
		struc_member(int_t,    texture_format,  1)
  
	; Depth buffer attachment texture
	; Texture depth;  
		struc_member(uint32_t, depth_id,      1)
		struc_member(int_t,    depth_width,   1)
		struc_member(int_t,    depth_height,  1)
		struc_member(int_t,    depth_mipmaps, 1)
		struc_member(int_t,    depth_format,  1)
endstruc

; RenderTexture2D, same as RenderTexture
struc RenderTexture2D
	; OpenGL framebuffer object id
	; unsigned int id;
	struc_member(uint32_t, id, 1)
  
	; Color buffer attachment texture
	; Texture texture;
		struc_member(uint32_t, texture_id,      1)
		struc_member(int_t,    texture_width,   1)
		struc_member(int_t,    texture_height,  1)
		struc_member(int_t,    texture_mipmaps, 1)
		struc_member(int_t,    texture_format,  1)
  
	; Depth buffer attachment texture
	; Texture depth;
		struc_member(uint32_t, depth_id,      1)
		struc_member(int_t,    depth_width,   1)
		struc_member(int_t,    depth_height,  1)
		struc_member(int_t,    depth_mipmaps, 1)
		struc_member(int_t,    depth_format,  1)
endstruc

; NPatchInfo, n-patch layout info
struc NPatchInfo
	; Texture source rectangle
	; Rectangle source;
		struc_member(float_t, source_x,      1)
		struc_member(float_t, source_y,      1)
		struc_member(float_t, source_width,  1)
		struc_member(float_t, source_height, 1)
  
	; Left border offset
	; int left;        
	struc_member(int_t, left, 1)
  
	; Top border offset
	; int top;         
	struc_member(int_t, top, 1)
  
	; Right border offset
	; int right;       
	struc_member(int_t, right, 1)
  
	; Bottom border offset
	; int bottom;      
	struc_member(int_t, bottom, 1)
  
	; Layout of the n-patch: 3x3, 1x3 or 3x1
	; int layout;      
	struc_member(int_t, layout, 1)
endstruc

; GlyphInfo, font characters glyphs info
struc GlyphInfo
	; Character value (Unicode)
	; int value;   
	struc_member(int_t, value, 1)
  
	; Character offset X when drawing
	; int offsetX; 
	struc_member(int_t, offsetX, 1)
  
	; Character offset Y when drawing
	; int offsetY; 
	struc_member(int_t, offsetY, 1)
  
	; Character advance position X
	; int advanceX;
	struc_member(int_t, advanceX, 1)
  
	; Character image data
	; Image image;
		struc_member(pointer_t, image_data,    1)
		struc_member(int_t,     image_width,   1)
		struc_member(int_t,     image_height,  1)
		struc_member(int_t,     image_mipmaps, 1)
		struc_member(int_t,     image_format,  1)
endstruc

; Font, font texture and GlyphInfo array data
struc Font
	; Base size (default chars height)
	; int baseSize;     
	struc_member(int_t, baseSize, 1)
  
	; Number of glyph characters
	; int glyphCount;   
	struc_member(int_t, glyphCount, 1)
  
	; Padding around the glyph characters
	; int glyphPadding; 
	struc_member(int_t, glyphPadding, 1)
  
	; Texture atlas containing the glyphs
	; Texture2D texture;
		struc_member(uint32_t, texture_id,      1)
		struc_member(int_t,    texture_width,   1)
		struc_member(int_t,    texture_height,  1)
		struc_member(int_t,    texture_mipmaps, 1)
		struc_member(int_t,    texture_format,  1)
  
	; Rectangles in texture for the glyphs
	; Rectangle* recs;  
	struc_member(pointer_t, recs, 1)
  
	; Glyphs info data
	; GlyphInfo* glyphs;
	struc_member(pointer_t, glyphs, 1)
endstruc

; Camera, defines position/orientation in 3d space
struc Camera3D
	; Camera position
	; Vector3 position;
		struc_member(float_t, position_x, 1)
		struc_member(float_t, position_y, 1)
		struc_member(float_t, position_z, 1)
  
	; Camera target it looks-at
	; Vector3 target;  
		struc_member(float_t, target_x, 1)
		struc_member(float_t, target_y, 1)
		struc_member(float_t, target_z, 1)
  
	; Camera up vector (rotation over its axis)
	; Vector3 up;      
		struc_member(float_t, up_x, 1)
		struc_member(float_t, up_y, 1)
		struc_member(float_t, up_z, 1)
  
	; Camera field-of-view aperture in Y (degrees) in perspective, used as near plane width in orthographic
	; float fovy;      
	struc_member(float_t, fovy, 1)
  
	; Camera projection: CAMERA_PERSPECTIVE or CAMERA_ORTHOGRAPHIC
	; int projection;  
	struc_member(int_t, projection, 1)
endstruc

; Camera type fallback, defaults to Camera3D
struc Camera
	; Camera position
	; Vector3 position;
		struc_member(float_t, position_x, 1)
		struc_member(float_t, position_y, 1)
		struc_member(float_t, position_z, 1)
  
	; Camera target it looks-at
	; Vector3 target;  
		struc_member(float_t, target_x, 1)
		struc_member(float_t, target_y, 1)
		struc_member(float_t, target_z, 1)
  
	; Camera up vector (rotation over its axis)
	; Vector3 up;      
		struc_member(float_t, up_x, 1)
		struc_member(float_t, up_y, 1)
		struc_member(float_t, up_z, 1)
  
	; Camera field-of-view aperture in Y (degrees) in perspective, used as near plane width in orthographic
	; float fovy;      
	struc_member(float_t, fovy, 1)
  
	; Camera projection: CAMERA_PERSPECTIVE or CAMERA_ORTHOGRAPHIC
	; int projection;  
	struc_member(int_t, projection, 1)
endstruc

; Camera2D, defines position/orientation in 2d space
struc Camera2D
	; Camera offset (displacement from target)
	; Vector2 offset;
		struc_member(float_t, offset_x, 1)
		struc_member(float_t, offset_y, 1)
  
	; Camera target (rotation and zoom origin)
	; Vector2 target;
		struc_member(float_t, target_x, 1)
		struc_member(float_t, target_y, 1)
  
	; Camera rotation in degrees
	; float rotation;
	struc_member(float_t, rotation, 1)
  
	; Camera zoom (scaling), should be 1.0f by default
	; float zoom;    
	struc_member(float_t, zoom, 1)
endstruc

; Mesh, vertex data and vao/vbo
struc Mesh
	; Number of vertices stored in arrays
	; int vertexCount;  
	struc_member(int_t, vertexCount, 1)
  
	; Number of triangles stored (indexed or not)
	; int triangleCount;
	struc_member(int_t, triangleCount, 1)

	; Vertex attributes data

		; Vertex position (XYZ - 3 components per vertex) (shader-location = 0)
		; float* vertices;        
		struc_member(pointer_t, vertices, 1)
	
		; Vertex texture coordinates (UV - 2 components per vertex) (shader-location = 1)
		; float* texcoords;       
		struc_member(pointer_t, texcoords, 1)
	
		; Vertex texture second coordinates (UV - 2 components per vertex) (shader-location = 5)
		; float* texcoords2;      
		struc_member(pointer_t, texcoords2, 1)
	
		; Vertex normals (XYZ - 3 components per vertex) (shader-location = 2)
		; float* normals;         
		struc_member(pointer_t, normals, 1)
	
		; Vertex tangents (XYZW - 4 components per vertex) (shader-location = 4)
		; float* tangents;        
		struc_member(pointer_t, tangents, 1)
	
		; Vertex colors (RGBA - 4 components per vertex) (shader-location = 3)
		; unsigned char* colors;  
		struc_member(pointer_t, colors, 1)
	
		; Vertex indices (in case vertex data comes indexed)
		; unsigned short* indices;
		struc_member(pointer_t, indices, 1)

	; Animation vertex data

		; Animated vertex positions (after bones transformations)
		; float* animVertices;   
		struc_member(pointer_t, animVertices, 1)
	
		; Animated normals (after bones transformations)
		; float* animNormals;    
		struc_member(pointer_t, animNormals, 1)
	
		; Vertex bone ids, max 255 bone ids, up to 4 bones influence by vertex (skinning) (shader-location = 6)
		; unsigned char* boneIds;
		struc_member(pointer_t, boneIds, 1)
	
		; Vertex bone weight, up to 4 bones influence by vertex (skinning) (shader-location = 7)
		; float* boneWeights;    
		struc_member(pointer_t, boneWeights, 1)
	
		; Bones animated transformation matrices
		; Matrix* boneMatrices;  
		struc_member(pointer_t, boneMatrices, 1)
	
		; Number of bones
		; int boneCount;         
		struc_member(int_t, boneCount, 1)

	; OpenGL identifiers

		; OpenGL Vertex Array Object id
		; unsigned int vaoId; 
		struc_member(uint32_t, vaoId, 1)
	
		; OpenGL Vertex Buffer Objects id (default vertex data)
		; unsigned int* vboId;
		struc_member(pointer_t, vboId, 1)
endstruc

; Shader
struc Shader
	; Shader program id
	; unsigned int id;
	struc_member(uint32_t, id, 1)

	.pad: resb 4
  
	; Shader locations array (RL_MAX_SHADER_LOCATIONS)
	; int* locs;      
	struc_member(pointer_t, locs, 1)
endstruc

; MaterialMap
struc MaterialMap
	; Material map texture
	; Texture2D texture;
		struc_member(uint32_t, texture_id,      1)
		struc_member(int_t,    texture_width,   1)
		struc_member(int_t,    texture_height,  1)
		struc_member(int_t,    texture_mipmaps, 1)
		struc_member(int_t,    texture_format,  1)
  
	; Material map color
	; Color color;      
		struc_member(uint8_t, color_r, 1)
		struc_member(uint8_t, color_g, 1)
		struc_member(uint8_t, color_b, 1)
		struc_member(uint8_t, color_a, 1)
  
	; Material map value
	; float value;      
	struc_member(float_t, value, 1)
endstruc

; Material, includes shader and maps
struc Material
	; Material shader
	; Shader shader;
		struc_member(uint32_t,  shader_id,   1)
		.shader_pad:            resb 4
		struc_member(pointer_t, shader_locs, 1)
  
	; Material maps array (MAX_MATERIAL_MAPS)
	; MaterialMap* maps;
	struc_member(pointer_t, maps, 1)
  
	; Material generic parameters (if required)
	; float params[4];  
	struc_member(float_t, params, 4)
endstruc

; Transform, vertex transformation data
struc Transform
	; Translation
	; Vector3 translation;
		struc_member(float_t, translation_x, 1)
		struc_member(float_t, translation_y, 1)
		struc_member(float_t, translation_z, 1)
  
	; Rotation
	; Quaternion rotation;
		struc_member(float_t, rotation_x, 1)
		struc_member(float_t, rotation_y, 1)
		struc_member(float_t, rotation_z, 1)
		struc_member(float_t, rotation_w, 1)
  
	; Scale
	; Vector3 scale;      
		struc_member(float_t, scale_x, 1)
		struc_member(float_t, scale_y, 1)
		struc_member(float_t, scale_z, 1)
endstruc

; Bone, skeletal animation bone
struc BoneInfo
	; Bone name
	; char name[32];
	struc_member(char_t, name, 32)
  
	; Bone parent
	; int parent;   
	struc_member(int_t, parent, 1)
endstruc

; Model, meshes, materials and animation data
struc Model
	; Local transform matrix
	; Matrix transform;
		struc_member(float_t, transform_m0,  1)
		struc_member(float_t, transform_m4,  1)
		struc_member(float_t, transform_m8,  1)
		struc_member(float_t, transform_m12, 1)
		struc_member(float_t, transform_m1,  1)
		struc_member(float_t, transform_m5,  1)
		struc_member(float_t, transform_m9,  1)
		struc_member(float_t, transform_m13, 1)
		struc_member(float_t, transform_m2,  1)
		struc_member(float_t, transform_m6,  1)
		struc_member(float_t, transform_m10, 1)
		struc_member(float_t, transform_m14, 1)
		struc_member(float_t, transform_m3,  1)
		struc_member(float_t, transform_m7,  1)
		struc_member(float_t, transform_m11, 1)
		struc_member(float_t, transform_m15, 1)

	; Number of meshes
	; int meshCount;      
	struc_member(int_t, meshCount, 1)
  
	; Number of materials
	; int materialCount;  
	struc_member(int_t, materialCount, 1)
  
	; Meshes array
	; Mesh* meshes;       
	struc_member(pointer_t, meshes, 1)
  
	; Materials array
	; Material* materials;
	struc_member(pointer_t, materials, 1)
  
	; Mesh material number
	; int* meshMaterial;  
	struc_member(pointer_t, meshMaterial, 1)
  

	; Animation data

		; Number of bones
		; int boneCount;      
		struc_member(int_t, boneCount, 1)

		.pad: resb 4
	
		; Bones information (skeleton)
		; BoneInfo* bones;    
		struc_member(pointer_t, bones, 1)
	
		; Bones base transformation (pose)
		; Transform* bindPose;
		struc_member(pointer_t, bindPose, 1)
endstruc

; ModelAnimation
struc ModelAnimation
	; Number of bones
	; int boneCount;         
	struc_member(int_t, boneCount, 1)
  
	; Number of animation frames
	; int frameCount;        
	struc_member(int_t, frameCount, 1)
  
	; Bones information (skeleton)
	; BoneInfo* bones;       
	struc_member(pointer_t, bones, 1)
  
	; Poses array by frame
	; Transform** framePoses;
	struc_member(pointer_t, framePoses, 1)
  
	; Animation name
	; char name[32];         
	struc_member(char_t, name, 32)
endstruc

; Ray, ray for raycasting
struc Ray
	; Ray position (origin)
	; Vector3 position; 
		struc_member(float_t, position_x, 1)
		struc_member(float_t, position_y, 1)
		struc_member(float_t, position_z, 1)
  
	; Ray direction (normalized)
	; Vector3 direction;
		struc_member(float_t, direction_x, 1)
		struc_member(float_t, direction_y, 1)
		struc_member(float_t, direction_z, 1)
endstruc

; RayCollision, ray hit information
struc RayCollision
	; Did the ray hit something?
	; bool hit;      
	struc_member(bool_t, hit, 1)

	.pad: resb 3
  
	; Distance to the nearest hit
	; float distance;
	struc_member(float_t, distance, 1)
  
	; Point of the nearest hit
	; Vector3 point; 
		struc_member(float_t, point_x, 1)
		struc_member(float_t, point_y, 1)
		struc_member(float_t, point_z, 1)
  
	; Surface normal of hit
	; Vector3 normal;
		struc_member(float_t, normal_x, 1)
		struc_member(float_t, normal_y, 1)
		struc_member(float_t, normal_z, 1)
endstruc

; BoundingBox
struc BoundingBox
	; Minimum vertex box-corner
	; Vector3 min;
		struc_member(float_t, min_x, 1)
		struc_member(float_t, min_y, 1)
		struc_member(float_t, min_z, 1)
  
	; Maximum vertex box-corner
	; Vector3 max;
		struc_member(float_t, max_x, 1)
		struc_member(float_t, max_y, 1)
		struc_member(float_t, max_z, 1)
endstruc

; Wave, audio wave data
struc Wave
	; Total number of frames (considering channels)
	; unsigned int frameCount;
	struc_member(uint32_t, frameCount, 1)
  
	; Frequency (samples per second)
	; unsigned int sampleRate;
	struc_member(uint32_t, sampleRate, 1)
  
	; Bit depth (bits per sample): 8, 16, 32 (24 not supported)
	; unsigned int sampleSize;
	struc_member(uint32_t, sampleSize, 1)
  
	; Number of channels (1-mono, 2-stereo, ...)
	; unsigned int channels;  
	struc_member(uint32_t, channels, 1)
  
	; Buffer data pointer
	; void* data;             
	struc_member(pointer_t, data, 1)
endstruc

; AudioStream, custom audio stream
struc AudioStream
	; Pointer to internal data used by the audio system
	; rAudioBuffer* buffer;      
	struc_member(pointer_t, buffer, 1)
  
	; Pointer to internal data processor, useful for audio effects
	; rAudioProcessor* processor;
	struc_member(pointer_t, processor, 1)

	; Frequency (samples per second)
	; unsigned int sampleRate;
	struc_member(uint32_t, sampleRate, 1)
  
	; Bit depth (bits per sample): 8, 16, 32 (24 not supported)
	; unsigned int sampleSize;
	struc_member(uint32_t, sampleSize, 1)
  
	; Number of channels (1-mono, 2-stereo, ...)
	; unsigned int channels;  
	struc_member(uint32_t, channels, 1)

	.pad: resb 4
endstruc

; Sound
struc Sound
	; Audio stream
	; AudioStream stream;
		struc_member(pointer_t, stream_buffer,     1)
		struc_member(pointer_t, stream_processor,  1)
		struc_member(uint32_t,  stream_sampleRate, 1)
		struc_member(uint32_t,  stream_sampleSize, 1)
		struc_member(uint32_t,  stream_channels,   1)
		.stream_pad:            resb 4
  
	; Total number of frames (considering channels)
	; unsigned int frameCount;
	struc_member(uint32_t, frameCount, 1)

	.pad: resb 4
endstruc

; Music, audio stream, anything longer than ~10 seconds should be streamed
struc Music
	; Audio stream
	; AudioStream stream;
		struc_member(pointer_t, stream_buffer,     1)
		struc_member(pointer_t, stream_processor,  1)
		struc_member(uint32_t,  stream_sampleRate, 1)
		struc_member(uint32_t,  stream_sampleSize, 1)
		struc_member(uint32_t,  stream_channels,   1)
		.stream_pad:            resb 4
  
	; Total number of frames (considering channels)
	; unsigned int frameCount;
	struc_member(uint32_t, frameCount, 1)
  
	; Music looping enable
	; bool looping;           
	struc_member(bool_t, looping, 1)

	.pad1: resb 3

	; Type of music context (audio filetype)
	; int ctxType;  
	struc_member(int_t, ctxType, 1)

	.pad2: resb 4
  
	; Audio context data, depends on type
	; void* ctxData;
	struc_member(pointer_t, ctxData, 1)
endstruc

; VrDeviceInfo, Head-Mounted-Display device parameters
struc VrDeviceInfo
	; Horizontal resolution in pixels
	; int hResolution;              
	struc_member(int_t, hResolution, 1)
  
	; Vertical resolution in pixels
	; int vResolution;              
	struc_member(int_t, vResolution, 1)
  
	; Horizontal size in meters
	; float hScreenSize;            
	struc_member(float_t, hScreenSize, 1)
  
	; Vertical size in meters
	; float vScreenSize;            
	struc_member(float_t, vScreenSize, 1)
  
	; Distance between eye and display in meters
	; float eyeToScreenDistance;    
	struc_member(float_t, eyeToScreenDistance, 1)
  
	; Lens separation distance in meters
	; float lensSeparationDistance; 
	struc_member(float_t, lensSeparationDistance, 1)
  
	; IPD (distance between pupils) in meters
	; float interpupillaryDistance; 
	struc_member(float_t, interpupillaryDistance, 1)
  
	; Lens distortion constant parameters
	; float lensDistortionValues[4];
	struc_member(float_t, lensDistortionValues, 4)
  
	; Chromatic aberration correction parameters
	; float chromaAbCorrection[4];  
	struc_member(float_t, chromaAbCorrection, 4)
endstruc

; VrStereoConfig, VR stereo rendering configuration for simulator
struc VrStereoConfig
	; VR projection matrices (per eye)
	; Matrix projection[2];
		struc_member(float_t, projection_0_m0,  1)
		struc_member(float_t, projection_0_m4,  1)
		struc_member(float_t, projection_0_m8,  1)
		struc_member(float_t, projection_0_m12, 1)
		struc_member(float_t, projection_0_m1,  1)
		struc_member(float_t, projection_0_m5,  1)
		struc_member(float_t, projection_0_m9,  1)
		struc_member(float_t, projection_0_m13, 1)
		struc_member(float_t, projection_0_m2,  1)
		struc_member(float_t, projection_0_m6,  1)
		struc_member(float_t, projection_0_m10, 1)
		struc_member(float_t, projection_0_m14, 1)
		struc_member(float_t, projection_0_m3,  1)
		struc_member(float_t, projection_0_m7,  1)
		struc_member(float_t, projection_0_m11, 1)
		struc_member(float_t, projection_0_m15, 1)

		struc_member(float_t, projection_1_m0,  1)
		struc_member(float_t, projection_1_m4,  1)
		struc_member(float_t, projection_1_m8,  1)
		struc_member(float_t, projection_1_m12, 1)
		struc_member(float_t, projection_1_m1,  1)
		struc_member(float_t, projection_1_m5,  1)
		struc_member(float_t, projection_1_m9,  1)
		struc_member(float_t, projection_1_m13, 1)
		struc_member(float_t, projection_1_m2,  1)
		struc_member(float_t, projection_1_m6,  1)
		struc_member(float_t, projection_1_m10, 1)
		struc_member(float_t, projection_1_m14, 1)
		struc_member(float_t, projection_1_m3,  1)
		struc_member(float_t, projection_1_m7,  1)
		struc_member(float_t, projection_1_m11, 1)
		struc_member(float_t, projection_1_m15, 1)
  
	; VR view offset matrices (per eye)
	; Matrix viewOffset[2];
		struc_member(float_t, viewOffset_0_m0,  1)
		struc_member(float_t, viewOffset_0_m4,  1)
		struc_member(float_t, viewOffset_0_m8,  1)
		struc_member(float_t, viewOffset_0_m12, 1)
		struc_member(float_t, viewOffset_0_m1,  1)
		struc_member(float_t, viewOffset_0_m5,  1)
		struc_member(float_t, viewOffset_0_m9,  1)
		struc_member(float_t, viewOffset_0_m13, 1)
		struc_member(float_t, viewOffset_0_m2,  1)
		struc_member(float_t, viewOffset_0_m6,  1)
		struc_member(float_t, viewOffset_0_m10, 1)
		struc_member(float_t, viewOffset_0_m14, 1)
		struc_member(float_t, viewOffset_0_m3,  1)
		struc_member(float_t, viewOffset_0_m7,  1)
		struc_member(float_t, viewOffset_0_m11, 1)
		struc_member(float_t, viewOffset_0_m15, 1)

		struc_member(float_t, viewOffset_1_m0,  1)
		struc_member(float_t, viewOffset_1_m4,  1)
		struc_member(float_t, viewOffset_1_m8,  1)
		struc_member(float_t, viewOffset_1_m12, 1)
		struc_member(float_t, viewOffset_1_m1,  1)
		struc_member(float_t, viewOffset_1_m5,  1)
		struc_member(float_t, viewOffset_1_m9,  1)
		struc_member(float_t, viewOffset_1_m13, 1)
		struc_member(float_t, viewOffset_1_m2,  1)
		struc_member(float_t, viewOffset_1_m6,  1)
		struc_member(float_t, viewOffset_1_m10, 1)
		struc_member(float_t, viewOffset_1_m14, 1)
		struc_member(float_t, viewOffset_1_m3,  1)
		struc_member(float_t, viewOffset_1_m7,  1)
		struc_member(float_t, viewOffset_1_m11, 1)
		struc_member(float_t, viewOffset_1_m15, 1)
  
	; VR left lens center
	; float leftLensCenter[2];   
	struc_member(float_t, leftLensCenter, 2)
  
	; VR right lens center
	; float rightLensCenter[2];  
	struc_member(float_t, rightLensCenter, 2)
  
	; VR left screen center
	; float leftScreenCenter[2]; 
	struc_member(float_t, leftScreenCenter, 2)
  
	; VR right screen center
	; float rightScreenCenter[2];
	struc_member(float_t, rightScreenCenter, 2)
  
	; VR distortion scale
	; float scale[2];            
	struc_member(float_t, scale, 2)
  
	; VR distortion scale in
	; float scaleIn[2];          
	struc_member(float_t, scaleIn, 2)
endstruc

; File path list
struc FilePathList
	; Filepaths max entries
	; unsigned int capacity;
	struc_member(uint32_t, capacity, 1)
  
	; Filepaths entries count
	; unsigned int count;   
	struc_member(uint32_t, count, 1)
  
	; Filepaths entries
	; char** paths;         
	struc_member(pointer_t, paths, 1)
endstruc

; Automation event
struc AutomationEvent
	; Event frame
	; unsigned int frame;
	struc_member(uint32_t, frame, 1)
  
	; Event type (AutomationEventType)
	; unsigned int type; 
	struc_member(uint32_t, type, 1)
  
	; Event parameters (if required)
	; int params[4];     
	struc_member(int_t, params, 4)
endstruc

; Automation event list
struc AutomationEventList
	; Events max entries (MAX_AUTOMATION_EVENTS)
	; unsigned int capacity;  
	struc_member(uint32_t, capacity, 1)
  
	; Events entries count
	; unsigned int count;     
	struc_member(uint32_t, count, 1)
  
	; Events entries
	; AutomationEvent* events;
	struc_member(pointer_t, events, 1)
endstruc

%endif ; RAY_TYPES_INC
