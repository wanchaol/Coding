#ifndef GRAPH_H
#define GRAPH_H 

#include <string>
#include "vertex.h"

class Graph {
	public:
		Graph() = default;

		void insertVertex(std::string);
		void insertEdge(std::string, std::string);
		void removeEdge(std::string, std::string);

		friend std::ostream& operator<<(std::ostream& , const Graph&);


	private:
		std::map<std::string, Vertex> vertexes;






}
#endif /* ifndef GRAPH_H */
