#include <vtkSmartPointer.h>
#include <vtkPoints.h>
#include <vtkCellArray.h>
#include <vtkPolyData.h>
#include <vtkPolyDataMapper.h>
#include <vtkActor.h>
#include <vtkRenderer.h>
#include <vtkRenderWindow.h>
#include <vtkRenderWindowInteractor.h>
#include <vtkPointSource.h>
#include <vtkProperty.h>

int main()
{
    // Create points for the polyline
    vtkSmartPointer<vtkPoints> points =
        vtkSmartPointer<vtkPoints>::New();
    points->InsertNextPoint(0, 0, 0); // Starting point
    points->InsertNextPoint(1, 1, 0); // Endpoint

    // Create a polyline
    vtkSmartPointer<vtkCellArray> lines =
        vtkSmartPointer<vtkCellArray>::New();
    lines->InsertNextCell(2);
    lines->InsertCellPoint(0);
    lines->InsertCellPoint(1);

    // Create a PolyData object
    vtkSmartPointer<vtkPolyData> polylineData =
        vtkSmartPointer<vtkPolyData>::New();
    polylineData->SetPoints(points);
    polylineData->SetLines(lines);

    // Create a mapper for the polyline
    vtkSmartPointer<vtkPolyDataMapper> polylineMapper =
        vtkSmartPointer<vtkPolyDataMapper>::New();
    polylineMapper->SetInputData(polylineData);

    // Create an actor for the polyline
    vtkSmartPointer<vtkActor> polylineActor =
        vtkSmartPointer<vtkActor>::New();
    polylineActor->SetMapper(polylineMapper);
    polylineActor->GetProperty()->SetColor(0, 1, 0); // Set color to green

    // Create a renderer
    vtkSmartPointer<vtkRenderer> renderer =
        vtkSmartPointer<vtkRenderer>::New();

    // Create a render window
    vtkSmartPointer<vtkRenderWindow> renderWindow =
        vtkSmartPointer<vtkRenderWindow>::New();
    renderWindow->AddRenderer(renderer);

    // Create a render window interactor
    vtkSmartPointer<vtkRenderWindowInteractor> renderWindowInteractor =
        vtkSmartPointer<vtkRenderWindowInteractor>::New();
    renderWindowInteractor->SetRenderWindow(renderWindow);

    // Add the polyline actor to the renderer
    renderer->AddActor(polylineActor);

    // Create a point source for the animated point
    vtkSmartPointer<vtkPointSource> pointSource =
        vtkSmartPointer<vtkPointSource>::New();
    pointSource->SetCenter(0, 0, 0);
    pointSource->SetNumberOfPoints(1);

    // Create a mapper for the animated point
    vtkSmartPointer<vtkPolyDataMapper> pointMapper =
        vtkSmartPointer<vtkPolyDataMapper>::New();
    pointMapper->SetInputConnection(pointSource->GetOutputPort());

    // Create an actor for the animated point
    vtkSmartPointer<vtkActor> pointActor =
        vtkSmartPointer<vtkActor>::New();
    pointActor->SetMapper(pointMapper);
    pointActor->GetProperty()->SetColor(1, 0, 0); // Set color to red

    // Add the animated point actor to the renderer
    renderer->AddActor(pointActor);

    // Set up the camera
    renderer->ResetCamera();

    // Start the rendering loop
    renderWindow->Render();
    renderWindowInteractor->Start();

    return 0;
}