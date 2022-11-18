// Copyright 2022 Nam Ji-Won

#include "mesh.h"

#include <iostream>
#include <cstdio>
#include <cmath>

#include <GL/glut.h>

static const float k_big_num = 1000000000000000000.0;

CMesh::CMesh() : num_vertices(0), num_polygons(0), num_normals(0),
	vertices(NULL), polygons(NULL), normals(NULL),
	min_x(k_big_num), min_y(k_big_num), min_z(k_big_num),
	max_x(-k_big_num), max_y(-k_big_num), max_z(-k_big_num){}

CMesh::~CMesh() {
	if (vertices) delete[] vertices;
	if (polygons) delete[] polygons;
}

void CMesh::LoadMesh(char* mesh_file_name) {
	FILE* file_ptr = fopen(mesh_file_name, "r");

	if (!mesh_file_name || !file_ptr) {
		std::cout << "!! File READ ERROR !!" << std::endl;
		exit(0);
	}

	fscanf(file_ptr, "%d", &num_vertices);
	vertices = new CVertex[num_vertices];

	for (int i = 0; i < num_vertices; ++i) {
		fscanf(file_ptr, "%f", &vertices[i].x);
		fscanf(file_ptr, "%f", &vertices[i].y);
		fscanf(file_ptr, "%f", &vertices[i].z);
	}

	fscanf(file_ptr, "%d", &num_polygons);
	polygons = new CFace[num_polygons];

	for (int i = 0; i < num_polygons; ++i) {
		fscanf(file_ptr, "%f", &polygons[i].vertex_0);
		fscanf(file_ptr, "%f", &polygons[i].vertex_1);
		fscanf(file_ptr, "%f", &polygons[i].vertex_2);
	}

	normals = new CVertex[num_vertices];
	ComputeNormals();
}

void CMesh::DrawMesh() {

	if (!vertices || !polygons) return;

	glBegin(GL_POINTS);

	for (int i = 0; i < num_vertices; ++i)
		glVertex3f(vertices[i].x, vertices[i].y, vertices[i].z);

	glEnd();

	for (int i = 0; i < num_polygons; ++i) {
		int index_1 = polygons[i].vertex_0,
			index_2 = polygons[i].vertex_1,
			index_3 = polygons[i].vertex_2;

		glBegin(GL_LINE_LOOP);
			glVertex3f(vertices[index_1].x, vertices[index_1].y, vertices[index_1].z);
			glVertex3f(vertices[index_2].x, vertices[index_2].y, vertices[index_2].z);
			glVertex3f(vertices[index_3].x, vertices[index_3].y, vertices[index_3].z);
		glEnd();
	}

	glBegin(GL_TRIANGLES);

	for (int i = 0; i < num_polygons; ++i) {
		CVertex
		point_0 = vertices[polygons[i].vertex_0],
		point_1 = vertices[polygons[i].vertex_1],
		point_2 = vertices[polygons[i].vertex_2],
		vertex_0, vertex_1, normal;

		vertex_0.x = point_1.x - point_0.x;
		vertex_0.y = point_1.y - point_0.y;
		vertex_0.z = point_1.z - point_0.z;

		vertex_1.x = point_2.x - point_0.x;
		vertex_1.y = point_2.y - point_0.y;
		vertex_1.z = point_2.z - point_0.z;
		
		normal.x = vertex_0.y * vertex_1.z - vertex_0.z * vertex_1.y;
		normal.y = vertex_0.z * vertex_1.x - vertex_0.x * vertex_1.z;
		normal.z = vertex_0.x * vertex_1.y - vertex_0.y * vertex_1.x;

		float distance = sqrt(pow(normal.x, 2) + pow(normal.y, 2) + pow(normal.z, 2));
		normal.x /= distance;
		normal.y /= distance;
		normal.z /= distance;

		glNormal3f(normal.x, normal.y, normal.z);
		glVertex3f(point_0.x, point_0.y, point_0.z);
		glVertex3f(point_1.x, point_1.y, point_1.z);
		glVertex3f(point_2.x, point_2.y, point_2.z);
	}
	glEnd();

	for (int i = 0; i < num_vertices; ++i)
		normals[i].x = normals[i].y = normals[i].z = 0.0;

	for (int i = 0; i < num_polygons; ++i) {
		int vtx_0 = polygons[i].vertex_0,
			vtx_1 = polygons[i].vertex_1,
			vtx_2 = polygons[i].vertex_2;

		CVertex
		point_0 = vertices[vtx_0],
		point_1 = vertices[vtx_1],
		point_2 = vertices[vtx_2],
		vertex_0, vertex_1, normal;

		vertex_0.x = point_1.x - point_0.x;
		vertex_0.y = point_1.y - point_0.y;
		vertex_0.z = point_1.z - point_0.z;

		vertex_1.x = point_2.x - point_0.x;
		vertex_1.y = point_2.y - point_0.y;
		vertex_1.z = point_2.z - point_0.z;

		normal.x = vertex_0.y * vertex_1.z - vertex_0.z * vertex_1.y;
		normal.y = vertex_0.z * vertex_1.x - vertex_0.x * vertex_1.z;
		normal.z = vertex_0.x * vertex_1.y - vertex_0.y * vertex_1.x;

		normals[vtx_0].x += normal.x;
		normals[vtx_0].y += normal.y;
		normals[vtx_0].z += normal.z;

		normals[vtx_1].x += normal.x;
		normals[vtx_1].y += normal.y;
		normals[vtx_1].z += normal.z;

		normals[vtx_2].x += normal.x;
		normals[vtx_2].y += normal.y;
		normals[vtx_2].z += normal.z;

		for (int i = 0; i < num_vertices; ++i) {
			float distance = sqrt(pow(normal.x, 2) + pow(normal.y, 2) + pow(normal.z, 2));
			normal.x /= distance;
			normal.y /= distance;
			normal.z /= distance;
		}
	}
}