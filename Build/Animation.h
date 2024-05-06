//#pragma once
//#include"Trajectory.h"
//#include"DataGenerator.h"
//#include <vtkCommand.h>
//#include <vtkMapper.h>
//#include <vtkActor.h>
//#include <vtkRenderer.h>
//#include <vtkRenderWindow.h>
//#include <vtkRenderWindowInteractor.h>
//#include <vtkMath.h>
//
//class Animation : public vtkCommand
//{
//public:
//	static Animation* New()
//	{
//		std::cout << "Animation pointer is created !" << "\n";
//		
//		return new Animation;
//	}
//
//	virtual void Execute(vtkObject* caller, unsigned long eventId, void* callData) override;
//	
//	Trajectory* _trajectory;
//	//vtkRenderWindow* _RenderWindow;
//	vtkRenderWindowInteractor* _renderWindowInteractor;
//	//vtkActor* _PointActor;
//	vtkSmartPointer<vtkPolyDataMapper> _PolylineMapper = vtkSmartPointer<vtkPolyDataMapper>::New();
//	
//
//	double step{ 0.01 };
//	int index{ 0 };
//	double AnimationParameter{ 0.0 };
//
//};
