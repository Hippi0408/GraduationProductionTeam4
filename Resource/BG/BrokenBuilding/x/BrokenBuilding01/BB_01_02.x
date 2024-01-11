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
 28;
 23.23000;96.00000;-50.00000;,
 23.23000;85.83810;-23.23000;,
 -13.17905;63.01890;-23.23000;,
 -13.17905;73.18079;-50.00000;,
 23.23000;67.33810;23.23000;,
 11.88475;44.51890;23.23000;,
 23.23000;54.84310;50.00000;,
 0.58475;37.44180;50.00000;,
 -50.00000;54.84310;50.00000;,
 -50.00000;67.33810;23.23000;,
 11.88475;44.51890;23.23000;,
 0.58475;37.44180;50.00000;,
 -50.00000;85.83810;-23.23000;,
 -13.17905;63.01890;-23.23000;,
 -50.00000;96.00000;-50.00000;,
 -13.17905;73.18079;-50.00000;,
 23.23000;67.33810;23.23000;,
 -50.00000;67.33810;23.23000;,
 23.23000;85.83810;-23.23000;,
 -50.00000;85.83810;-23.23000;,
 23.23000;96.00000;-50.00000;,
 -50.00000;96.00000;-50.00000;,
 0.58475;37.44180;50.00000;,
 23.23000;54.84310;50.00000;,
 -50.00000;54.84310;50.00000;,
 -13.17905;73.18079;-50.00000;,
 -50.00000;96.00000;-50.00000;,
 23.23000;96.00000;-50.00000;;
 
 11;
 4;0,1,2,3;,
 4;1,4,5,2;,
 4;4,6,7,5;,
 4;8,9,10,11;,
 4;9,12,13,10;,
 4;12,14,15,13;,
 4;8,6,16,17;,
 4;17,16,18,19;,
 4;19,18,20,21;,
 3;22,23,24;,
 3;25,26,27;;
 
 MeshMaterialList {
  4;
  11;
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  0,
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
  14;
  -0.501326;-0.808937;-0.307073;,
  0.505554;-0.806634;-0.306198;,
  0.583694;-0.715810;-0.383299;,
  0.723062;-0.635029;-0.271881;,
  0.768221;-0.635085;-0.080647;,
  -0.309814;-0.869225;-0.385310;,
  -0.367576;-0.872885;-0.320872;,
  -0.462691;-0.840808;-0.280998;,
  0.000000;0.906153;0.422950;,
  0.000000;0.917987;0.396612;,
  0.000000;0.932012;0.362429;,
  0.000000;0.934908;0.354891;,
  0.000000;-0.000000;1.000000;,
  0.000000;0.000000;-1.000000;;
  11;
  4;1,2,2,1;,
  4;2,3,3,2;,
  4;3,4,4,3;,
  4;5,6,6,5;,
  4;6,7,7,6;,
  4;7,0,0,7;,
  4;8,8,9,9;,
  4;9,9,10,10;,
  4;10,10,11,11;,
  3;12,12,12;,
  3;13,13,13;;
 }
 MeshTextureCoords {
  28;
  0.000000;0.000000;,
  0.333330;0.000000;,
  0.333330;1.000000;,
  0.000000;1.000000;,
  0.666670;0.000000;,
  0.666670;1.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  0.000000;0.000000;,
  0.333330;0.000000;,
  0.333330;1.000000;,
  0.000000;1.000000;,
  0.666670;0.000000;,
  0.666670;1.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  1.000000;0.333330;,
  0.000000;0.333330;,
  1.000000;0.666670;,
  0.000000;0.666670;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  0.511695;0.910853;,
  0.964600;0.803438;,
  -0.500000;0.803438;,
  0.236419;0.690242;,
  -0.500000;0.549383;,
  0.964600;0.549383;;
 }
}
