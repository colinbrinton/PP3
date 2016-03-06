
class Graph
{
private:
	int** adjMatrix;
	int numVert = 0;

	void allocateMatrix(int size);
	void allocateVisited();
	void matrixCleanUp(int size);
	void recursiveDFS(int vertex, int* visited);

public:
	//Graph();
	~Graph();
	void load(char* filename);
	void display();
	void displayDFS(int vertex);
	void displayBFS(int vertex);
};