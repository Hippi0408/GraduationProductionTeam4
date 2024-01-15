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
 110;
 28.50382;77.99990;-27.00000;,
 28.50382;71.88925;-12.54420;,
 -16.17175;58.16730;-12.54420;,
 -16.17175;64.27796;-27.00000;,
 28.50382;60.76458;12.54420;,
 -32.52336;47.04263;12.54420;,
 28.50382;53.25093;27.00000;,
 -46.38896;42.78698;27.00000;,
 -71.62500;53.25103;27.00000;,
 -71.62500;60.76467;12.54420;,
 -32.52336;47.04263;12.54420;,
 -46.38896;42.78698;27.00000;,
 -71.62500;71.88936;-12.54420;,
 -16.17175;58.16730;-12.54420;,
 -71.62500;78.00000;-27.00000;,
 -16.17175;64.27796;-27.00000;,
 28.50382;60.76458;12.54420;,
 -71.62500;60.76467;12.54420;,
 28.50382;71.88925;-12.54420;,
 -71.62500;71.88936;-12.54420;,
 28.50382;77.99990;-27.00000;,
 -71.62500;78.00000;-27.00000;,
 -46.38896;42.78698;27.00000;,
 28.50382;53.25093;27.00000;,
 -71.62500;53.25103;27.00000;,
 -16.17175;64.27796;-27.00000;,
 -71.62500;78.00000;-27.00000;,
 28.50382;77.99990;-27.00000;,
 71.62500;71.88936;-12.54420;,
 71.62500;60.76467;12.54420;,
 71.62500;46.56975;12.54420;,
 71.62500;46.56975;-12.54420;,
 71.62500;78.00000;-27.00000;,
 71.62500;29.86281;-12.54420;,
 71.62500;-0.12739;-27.00000;,
 71.62500;29.86281;12.54420;,
 71.62500;53.25103;27.00000;,
 71.62500;-0.12739;27.00000;,
 28.50382;53.25093;27.00000;,
 -46.38896;42.78698;27.00000;,
 -71.62500;-0.12739;27.00000;,
 71.62500;-0.12739;27.00000;,
 -32.52336;47.04263;12.54420;,
 -16.17175;58.16730;-12.54420;,
 -31.43948;-0.12750;-27.00000;,
 -71.62500;-0.12739;27.00000;,
 28.50382;53.25093;27.00000;,
 71.62500;53.25103;27.00000;,
 71.62500;60.76467;12.54420;,
 28.50382;60.76458;12.54420;,
 -32.52336;47.04263;12.54420;,
 28.50382;60.76458;12.54420;,
 28.50382;71.88925;-12.54420;,
 -16.17175;58.16730;-12.54420;,
 71.62500;71.88936;-12.54420;,
 28.50382;71.88925;-12.54420;,
 28.50382;77.99990;-27.00000;,
 -16.17175;64.27796;-27.00000;,
 71.62500;78.00000;-27.00000;,
 28.50382;77.99990;-27.00000;,
 -31.43948;-0.12750;-27.00000;,
 71.62500;-0.12739;-27.00000;,
 71.62500;-0.12739;27.00000;,
 -71.62500;-0.12739;27.00000;,
 -46.38896;42.78698;27.00000;,
 71.62500;53.25103;27.00000;,
 -16.17175;64.27796;-27.00000;,
 -31.43948;-0.12750;-27.00000;,
 -16.17175;64.27796;-27.00000;,
 28.50382;77.99990;-27.00000;,
 71.62500;-0.12739;-27.00000;,
 71.62500;78.00000;-27.00000;,
 -46.38896;42.78698;27.00000;,
 28.50382;60.76458;12.54420;,
 -46.38896;42.78698;27.00000;,
 -16.17175;64.27796;-27.00000;,
 -46.38896;42.78698;27.00000;,
 -37.40355;46.56963;12.54420;,
 -37.40355;46.56963;-12.54420;,
 -16.17175;64.27796;-27.00000;,
 -37.40355;29.86271;-12.54420;,
 -31.43948;-0.12750;-27.00000;,
 -37.40355;29.86271;12.54420;,
 -46.38896;42.78698;27.00000;,
 -71.62500;-0.12739;27.00000;,
 -71.62500;60.76467;12.54420;,
 -71.62500;71.88936;-12.54420;,
 -71.62500;-0.12739;-27.00000;,
 -71.62500;-0.12739;27.00000;,
 -71.62500;60.76467;12.54420;,
 -46.38896;42.78698;27.00000;,
 -16.17175;64.27796;-27.00000;,
 -71.62500;71.88936;-12.54420;,
 -71.62500;53.25103;27.00000;,
 -71.62500;-0.12739;27.00000;,
 -46.38896;42.78698;27.00000;,
 -71.62500;53.25103;27.00000;,
 -71.62500;78.00000;-27.00000;,
 -31.43948;-0.12750;-27.00000;,
 -71.62500;78.00000;-27.00000;,
 -16.17175;64.27796;-27.00000;,
 -71.62500;60.76467;12.54420;,
 -71.62500;53.25103;27.00000;,
 -46.38896;42.78698;27.00000;,
 -71.62500;-0.12739;-27.00000;,
 -16.17175;64.27796;-27.00000;,
 -71.62500;78.00000;-27.00000;,
 -71.62500;-0.12739;27.00000;,
 -71.62500;-0.12739;-27.00000;,
 -31.43948;-0.12750;-27.00000;;
 
 49;
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
 3;25,26,27;,
 4;28,29,30,31;,
 4;32,31,33,34;,
 4;31,30,35,33;,
 4;30,36,37,35;,
 4;33,35,37,34;,
 4;38,39,40,41;,
 4;42,43,44,45;,
 4;46,47,48,49;,
 4;50,51,52,53;,
 4;49,48,54,55;,
 4;53,52,56,57;,
 4;55,54,58,59;,
 4;60,61,62,63;,
 3;36,30,29;,
 3;45,64,42;,
 3;41,65,38;,
 3;44,43,66;,
 3;67,68,69;,
 3;70,69,71;,
 3;32,28,31;,
 3;72,51,50;,
 3;73,74,46;,
 3;69,70,67;,
 4;75,76,77,78;,
 4;79,78,80,81;,
 4;78,77,82,80;,
 4;77,83,84,82;,
 4;80,82,84,81;,
 4;85,86,87,88;,
 4;89,90,91,92;,
 3;88,93,85;,
 3;94,95,96;,
 3;87,86,97;,
 3;98,99,100;,
 3;101,102,103;,
 3;99,98,104;,
 3;105,106,92;,
 3;107,108,109;;
 
 MeshMaterialList {
  4;
  49;
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  0,
  0,
  1,
  1,
  1,
  1,
  1,
  0,
  2,
  2,
  2,
  2,
  2,
  2,
  3,
  1,
  2,
  0,
  2,
  0,
  0,
  1,
  2,
  2,
  0,
  2,
  2,
  2,
  2,
  2,
  1,
  2,
  1,
  0,
  1,
  0,
  2,
  0,
  2,
  3;;
  Material {
   0.800000;0.800000;0.800000;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
   TextureFilename {
    "texture\\bill003.jpg";
   }
  }
  Material {
   0.800000;0.800000;0.800000;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
   TextureFilename {
    "texture\\bill003.jpg";
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
 }
 MeshNormals {
  51;
  -0.222226;-0.898056;-0.379620;,
  0.272224;-0.886301;-0.374651;,
  0.256765;-0.898919;-0.354988;,
  0.204885;-0.924282;-0.322064;,
  0.025801;-0.920781;-0.389226;,
  0.008779;-0.917731;-0.397105;,
  -0.042220;-0.913318;-0.405054;,
  0.168326;-0.936197;-0.308547;,
  -0.076146;-0.911238;-0.404779;,
  -0.315315;-0.822812;-0.472819;,
  -0.286406;-0.840205;-0.460465;,
  -0.239903;-0.878114;-0.413959;,
  -0.272224;0.886301;0.374651;,
  -0.137417;0.912349;0.385662;,
  1.000000;0.000000;0.000000;,
  -0.925585;0.321486;-0.199848;,
  0.000000;0.000000;1.000000;,
  -0.649555;0.668472;-0.362247;,
  -0.118490;0.928136;0.352878;,
  -0.129467;0.916119;0.379426;,
  -1.000000;0.000000;0.000000;,
  0.766579;-0.302037;0.566683;,
  0.798486;-0.185507;0.572719;,
  0.909204;-0.128296;0.396091;,
  0.924426;-0.159777;0.346278;,
  0.895349;-0.209479;0.393025;,
  0.908920;-0.239221;0.341523;,
  0.798909;-0.345060;0.492624;,
  0.833336;-0.231590;0.501914;,
  0.000001;0.887302;0.461190;,
  0.000001;0.901163;0.433481;,
  0.000001;0.917658;0.397371;,
  0.000001;0.921088;0.389356;,
  0.000000;0.000000;-1.000000;,
  -0.753992;0.401430;-0.519951;,
  -0.061634;0.885614;0.460313;,
  -0.000002;0.887301;0.461190;,
  -0.000002;0.901163;0.433481;,
  -0.241104;0.910831;0.335046;,
  -0.256765;0.898919;0.354988;,
  -0.000002;0.917658;0.397371;,
  -0.000002;0.921088;0.389355;,
  0.000001;-1.000000;0.000001;,
  -0.421107;0.906948;-0.010644;,
  -0.968441;0.229575;0.097044;,
  0.304485;0.845150;0.439330;,
  0.242904;0.877874;0.412717;,
  0.345289;0.832729;0.432825;,
  0.000000;0.000000;-1.000000;,
  0.222226;0.898056;0.379619;,
  -0.000003;-1.000000;0.000000;;
  49;
  4;1,2,5,4;,
  4;2,3,6,5;,
  4;3,7,8,6;,
  4;9,10,6,8;,
  4;10,11,5,6;,
  4;11,0,4,5;,
  4;29,29,30,30;,
  4;30,30,31,31;,
  4;31,31,32,32;,
  3;16,16,16;,
  3;33,33,33;,
  4;14,14,14,14;,
  4;14,14,14,14;,
  4;14,14,14,14;,
  4;14,14,14,14;,
  4;14,14,14,14;,
  4;16,16,16,16;,
  4;17,15,15,34;,
  4;35,36,37,18;,
  4;38,18,19,39;,
  4;18,37,40,19;,
  4;39,19,13,12;,
  4;19,40,41,13;,
  4;42,42,42,42;,
  3;14,14,14;,
  3;34,43,17;,
  3;16,16,16;,
  3;15,15,44;,
  3;33,33,33;,
  3;33,33,33;,
  3;14,14,14;,
  3;43,18,17;,
  3;18,43,35;,
  3;33,33,33;,
  4;22,28,24,23;,
  4;22,23,25,21;,
  4;23,24,26,25;,
  4;24,28,27,26;,
  4;25,26,27,21;,
  4;20,20,20,20;,
  4;45,45,46,46;,
  3;20,20,20;,
  3;16,16,16;,
  3;20,20,20;,
  3;33,33,33;,
  3;45,47,45;,
  3;33,33,48;,
  3;46,49,46;,
  3;50,50,50;;
 }
 MeshTextureCoords {
  110;
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
  0.190740;0.394061;,
  0.690025;0.324301;,
  0.022500;0.324301;,
  0.392188;0.250788;,
  0.022500;0.159307;,
  0.690025;0.159308;,
  0.423975;-0.118034;,
  0.576025;-0.043869;,
  0.576025;0.050764;,
  0.423975;0.050764;,
  0.336364;-0.158771;,
  0.423975;0.162143;,
  0.336364;0.362078;,
  0.576025;0.162143;,
  0.663636;0.006222;,
  0.663636;0.362078;,
  0.690025;0.324301;,
  0.190740;0.394061;,
  0.022500;0.680157;,
  0.977500;0.680157;,
  0.667120;0.801280;,
  0.332880;0.727280;,
  0.140290;0.980000;,
  0.859710;0.980000;,
  0.666670;0.000000;,
  1.000000;0.000000;,
  1.000000;0.333330;,
  0.666670;0.333330;,
  0.000000;0.333330;,
  0.333330;0.333330;,
  0.333330;0.666670;,
  0.000000;0.666670;,
  1.000000;0.666670;,
  0.666670;0.666670;,
  0.333330;1.000000;,
  0.000000;1.000000;,
  1.000000;1.000000;,
  0.666670;1.000000;,
  -1.071974;-0.850000;,
  4.081250;-0.850000;,
  4.081250;1.850000;,
  -3.081250;1.850000;,
  0.859710;0.851260;,
  0.977500;0.324301;,
  0.140290;0.686630;,
  0.290403;0.680157;,
  0.392188;0.250788;,
  0.690025;0.159308;,
  0.977500;0.680157;,
  0.977500;0.159307;,
  0.166670;0.000000;,
  0.500000;0.333330;,
  0.333330;0.000000;,
  0.332880;0.636000;,
  0.859710;0.759980;,
  0.667120;0.804420;,
  0.332880;0.804420;,
  0.140290;0.595350;,
  0.332880;0.915560;,
  0.140290;0.980000;,
  0.667120;0.915560;,
  0.859710;0.851260;,
  0.859710;0.980000;,
  0.576025;-0.043869;,
  0.423975;-0.118034;,
  0.336364;0.362078;,
  0.663636;0.362078;,
  0.666670;0.333330;,
  1.000000;0.333330;,
  1.000000;0.666670;,
  0.666670;0.666670;,
  0.663636;0.006222;,
  0.022500;0.680157;,
  0.190740;0.394061;,
  0.022500;0.324301;,
  0.336364;-0.158771;,
  0.290403;0.680157;,
  0.022500;0.159307;,
  0.392188;0.250788;,
  0.166670;0.333330;,
  0.000000;0.000000;,
  0.333330;0.000000;,
  0.022500;0.680157;,
  1.000000;0.833330;,
  0.666670;1.000000;,
  -3.081250;1.850000;,
  -3.081250;-0.850000;,
  -1.071974;-0.850000;;
 }
}
