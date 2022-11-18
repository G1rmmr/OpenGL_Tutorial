#pragma once
#ifndef _mesh_sms_hh_
#define _mesh_sms_hh_

class CVertex {
public:
  float x, y, z;
};

class CFace {
public:
  int vertex_0, vertex_1, vertex_2;
};

class CMesh {
  int num_vertices, num_polygons, num_normals;
  CVertex *vertices, *normals;
  CFace *polygons;

public:
  float min_x, min_y, min_z;
  float max_x, max_y, max_z;

  CMesh();
  ~CMesh();

  void LoadMesh(char* mesh_file_name);
  void ComputeNormals();
  void DrawMesh();
};

#endif