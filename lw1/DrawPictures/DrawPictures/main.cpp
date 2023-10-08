
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <functional>
#include <algorithm>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <cmath>
#include <corecrt_math_defines.h>
#include "Canvas.h"
#include "shapes.h"
#include "Shape.h"
#include "Circle.h"
#include "Rectangle.h"
#include "Triangle.h"
#include "Line.h"
#include "Text.h"

using namespace std;
using namespace shapes;

void DialogueWithUser(Picture& picture);
void AddShape(Picture& picture);
shared_ptr<Shape> CreateCircle();
shared_ptr<Shape> CreateRectangle();
shared_ptr<Shape> CreateTriangle();
shared_ptr<Shape> CreateLine();
shared_ptr<Shape> CreateText();
void MoveShape(Picture& picture);
void MovePicture(Picture& picture);
void DeleteShape(Picture& picture);
void List(Picture& picture);
void ChangeColor(Picture& picture);
void ChangeShape(Picture& picture);
void DrawShape(Picture& picture);
void DrawPicture(Picture& picture);


const map<string, function<void(Picture&)>> COMMANDS
{
    {"addshape", AddShape},
    {"moveshape", MoveShape},
    {"movepicture", MovePicture},
    {"deleteshape", DeleteShape},
    {"list", List},
    {"changecolor", ChangeColor},
    {"changeshape", ChangeShape},
    {"drawshape", DrawShape},
    {"drawpicture", DrawPicture},
};

const map<string, function<shared_ptr<Shape>()>> CreateShapesFunctions
{
    {"circle", CreateCircle},
    {"rectangle", CreateRectangle},
    {"triangle", CreateTriangle},
    {"line", CreateLine},
    {"text", CreateText},
};



int main()
{
    Picture picture;
    DialogueWithUser(picture);
    
    return 0;
}

void DialogueWithUser(Picture& picture)
{
    string answer;
    cout << "Enter the command\n>";
    while (cin >> answer && answer != "exit")
    {
        transform(answer.begin(), answer.end(), answer.begin(), [](char& ch) {return tolower(ch);});
        if (COMMANDS.count(answer) == 1)
        {
            COMMANDS.find(answer)->second(picture);
        }
        else
        {
            cout << "Command is not recognized. Try again";
        }
        cout << "\n>";
    }
    picture.ShowFinalPicture();
    
}

void AddShape(Picture& picture)
{
    string type, id, color;
    cin >> id >> color >> type;
    if (CreateShapesFunctions.count(type) == 1)
    {
        shared_ptr<Shape> shape(CreateShapesFunctions.find(type)->second());
        picture.AddShape(id, color, type, shape);
    }
    else
    {
        cout << "No such shape. Try again";
    }
}

shared_ptr<Shape> CreateCircle()
{
    Point point;
    double radius;
    cin >> point.x >> point.y >> radius;
    Circle circle(point, radius);
    return make_shared<Circle>(circle);
}

shared_ptr<Shape> CreateRectangle()
{
    Point point;
    double width, height;
    cin >> point.x >> point.y >> width >> height;
    Rectangle rect(point, width, height);
    return make_shared<Rectangle>(rect);
}

shared_ptr<Shape> CreateTriangle()
{
    Point point1, point2, point3;
    cin >> point1.x >> point1.y >> point2.x >> point2.y >> point3.x >> point3.y;
    Triangle tr(point1, point2, point3);
    return make_shared<Triangle>(tr);
}

shared_ptr<Shape> CreateLine()
{ 
    Point point1, point2;
    cin >> point1.x >> point1.y >> point2.x >> point2.y;
    Line line(point1, point2);
    return make_shared<Line>(line);
}

shared_ptr<Shape> CreateText()
{
    Point point;
    double fontSize;
    string text;
    cin >> point.x >> point.y >> fontSize;
    getline(cin, text);
    return make_shared<Text>(Text(text, fontSize, point));
}

void MoveShape(Picture& picture)
{
    string id;
    cin >> id;
    if (!picture.Contains(id))
    {
        cout << "No shape with such id. Try again";
        return;
    }
    else
    {
        double dx, dy;
        cin >> dx >> dy;
        picture.MoveShape(id, dx, dy);
    }
}

void MovePicture(Picture& picture)
{
    double dx, dy;
    cin >> dx >> dy;
    picture.MovePicture(dx, dy);
}

void DeleteShape(Picture& picture)
{
    string id;
    cin >> id;
    if (picture.Contains(id))
    {
        picture.DeleteShape(id);
    }
    else
    {
        cout << "No shape with such id. Try again";
        return;
    }
}

void List(Picture& picture)
{
    picture.List();
}

void ChangeColor(Picture& picture)
{
    string id, hexColor;
    cin >> id >> hexColor;
    if (picture.Contains(id))
    {
        picture.ChangeColor(id, hexColor);
    }
    else
    {
        cout << "No shape with such id. Try again";
        return;
    }
    
}

void ChangeShape(Picture& picture)
{
    string id;
    cin >> id;
    if (picture.Contains(id))
    {
        string type;
        cin >> type;
        if (CreateShapesFunctions.count(type) == 1)
        {
            picture.ChangeShape(id, type, CreateShapesFunctions.find(type)->second());
        }
        else
        {
            cout << "No such shape. Try again";
        }
    }
    else
    {
        cout << "No shape with such id. Try again";
        return;
    }
}

void DrawShape(Picture& picture)
{
    string id;
    cin >> id;
    if (picture.Contains(id))
    {
        picture.DrawShape(id);
    }
    else
    {
        cout << "No shape with such id. Try again";
        return;
    }
}

void DrawPicture(Picture& picture)
{
    picture.DrawPicture();
}