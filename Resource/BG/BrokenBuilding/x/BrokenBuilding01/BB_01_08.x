xof 0302txt 0064
template Header {
 <3D82AB43-62DA-11cf-AB39-0020AF71E433>
 WORD major;
 WORD minor;
 DWORD flags;
}

template Vector {
 <3D82AB5E-62DA-11cf-AB39-0020AF71E433>
 FLOAT x;
 FLOAT y;
 FLOAT z;
}

template Coords2d {
 <F6F23F44-7686-11cf-8F52-0040333594A3>
 FLOAT u;
 FLOAT v;
}

template Matrix4x4 {
 <F6F23F45-7686-11cf-8F52-0040333594A3>
 array FLOAT matrix[16];
}

template ColorRGBA {
 <35FF44E0-6C7C-11cf-8F52-0040333594A3>
 FLOAT red;
 FLOAT green;
 FLOAT blue;
 FLOAT alpha;
}

template ColorRGB {
 <D3E16E81-7835-11cf-8F52-0040333594A3>
 FLOAT red;
 FLOAT green;
 FLOAT blue;
}

template IndexedColor {
 <1630B820-7842-11cf-8F52-0040333594A3>
 DWORD index;
 ColorRGBA indexColor;
}

template Boolean {
 <4885AE61-78E8-11cf-8F52-0040333594A3>
 WORD truefalse;
}

template Boolean2d {
 <4885AE63-78E8-11cf-8F52-0040333594A3>
 Boolean u;
 Boolean v;
}

template MaterialWrap {
 <4885AE60-78E8-11cf-8F52-0040333594A3>
 Boolean u;
 Boolean v;
}

template TextureFilename {
 <A42790E1-7810-11cf-8F52-0040333594A3>
 STRING filename;
}

template Material {
 <3D82AB4D-62DA-11cf-AB39-0020AF71E433>
 ColorRGBA faceColor;
 FLOAT power;
 ColorRGB specularColor;
 ColorRGB emissiveColor;
 [...]
}

template MeshFace {
 <3D82AB5F-62DA-11cf-AB39-0020AF71E433>
 DWORD nFaceVertexIndices;
 array DWORD faceVertexIndices[nFaceVertexIndices];
}

template MeshFaceWraps {
 <4885AE62-78E8-11cf-8F52-0040333594A3>
 DWORD nFaceWrapValues;
 Boolean2d faceWrapValues;
}

template MeshTextureCoords {
 <F6F23F40-7686-11cf-8F52-0040333594A3>
 DWORD nTextureCoords;
 array Coords2d textureCoords[nTextureCoords];
}

template MeshMaterialList {
 <F6F23F42-7686-11cf-8F52-0040333594A3>
 DWORD nMaterials;
 DWORD nFaceIndexes;
 array DWORD faceIndexes[nFaceIndexes];
 [Material]
}

template MeshNormals {
 <F6F23F43-7686-11cf-8F52-0040333594A3>
 DWORD nNormals;
 array Vector normals[nNormals];
 DWORD nFaceNormals;
 array MeshFace faceNormals[nFaceNormals];
}

template MeshVertexColors {
 <1630B821-7842-11cf-8F52-0040333594A3>
 DWORD nVertexColors;
 array IndexedColor vertexColors[nVertexColors];
}

template Mesh {
 <3D82AB44-62DA-11cf-AB39-0020AF71E433>
 DWORD nVertices;
 array Vector vertices[nVertices];
 DWORD nFaces;
 array MeshFace faces[nFaces];
 [...]
}

Header{
1;
0;
1;
}

Mesh {
 22;
 -26.14845;240.00000;-50.00000;,
 -4.90800;209.72532;-50.00000;,
 -23.23000;185.73640;-49.99995;,
 -40.08915;185.73640;-49.99995;,
 -26.14845;240.00000;50.00000;,
 -26.14845;240.00000;-50.00000;,
 -40.08915;185.73640;-49.99995;,
 -23.23000;156.10685;50.00005;,
 -26.14845;240.00000;50.00000;,
 -4.90800;196.24826;50.00000;,
 -4.90800;209.72532;-50.00000;,
 -26.14845;240.00000;-50.00000;,
 -40.08915;185.73640;-49.99995;,
 -23.23000;185.73640;-49.99995;,
 -4.90800;196.24826;50.00000;,
 -23.23000;156.10685;50.00005;,
 -4.90800;196.24826;50.00000;,
 -23.23000;185.73640;-49.99995;,
 -4.90800;209.72532;-50.00000;,
 -4.90800;196.24826;50.00000;,
 -26.14845;240.00000;50.00000;,
 -23.23000;156.10685;50.00005;;
 
 6;
 4;0,1,2,3;,
 4;4,5,6,7;,
 4;8,9,10,11;,
 4;12,13,14,15;,
 3;16,17,18;,
 3;19,20,21;;
 
 MeshMaterialList {
  4;
  6;
  0,
  1,
  1,
  1,
  1,
  0;;
  Material {
   0.800000;0.800000;0.800000;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
   TextureFilename {
    "texture\\bill001.jpg";
   }
  }
  Material {
   0.800000;0.800000;0.800000;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
   TextureFilename {
    "texture\\Concrete.png";
   }
  }
  Material {
   0.800000;0.800000;0.800000;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
   TextureFilename {
    "texture\\Concrete.png";
   }
  }
  Material {
   0.800000;0.800000;0.800000;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
   TextureFilename {
    "texture\\bill001.jpg";
   }
  }
 }
 MeshNormals {
  7;
  -0.000000;-0.000001;-1.000000;,
  0.861447;0.506991;0.029485;,
  -0.990919;0.108679;0.079168;,
  0.533933;-0.810690;-0.240204;,
  0.674406;-0.720000;-0.163634;,
  0.792071;-0.604960;-0.081531;,
  0.000001;0.000001;1.000000;;
  6;
  4;0,0,0,0;,
  4;2,2,2,2;,
  4;1,1,1,1;,
  4;3,4,4,3;,
  3;4,4,5;,
  3;6,6,6;;
 }
 MeshTextureCoords {
  22;
  -0.022969;-0.339506;,
  0.401840;-0.152625;,
  0.035400;-0.004546;,
  -0.301783;-0.004546;,
  0.859710;0.023860;,
  0.140290;0.023860;,
  0.140290;0.236410;,
  0.859710;0.354930;,
  0.311880;0.023860;,
  0.625120;0.023860;,
  0.625120;0.023860;,
  0.311880;0.023860;,
  0.211590;0.236410;,
  0.859710;0.423860;,
  0.464690;0.194360;,
  0.332880;0.354930;,
  0.859710;0.109110;,
  0.140290;0.423860;,
  0.140290;0.023860;,
  0.401840;-0.069434;,
  -0.022969;-0.339506;,
  0.035400;0.178353;;
 }
}
