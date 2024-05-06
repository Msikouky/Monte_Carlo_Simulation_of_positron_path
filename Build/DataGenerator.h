#include "Point.h"
#include <vector>
#include <vtkPoints.h>
#include <vtkPolyDataMapper.h>
#include <vtkActor.h>

class DataGenerator
{
public:
	DataGenerator();
	DataGenerator(const DataGenerator& dg);
	void setPoints(const std::vector<Point> &points);
	void setPointsToVtk(const std::vector<Point>& points);
	std::vector<Point> getPoints();
	DataGenerator& operator=(const DataGenerator& other);
	//vtkNew<vtkPoints> getPointsToVtk();
	void printPoints();
	void drawHistogram();

private:
	
	vtkNew<vtkPoints> _pointsToVtk;
	std::vector<Point> _dataPoints;


};