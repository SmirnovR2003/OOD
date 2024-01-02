using _10Sharp.Model;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _10Sharp.Controler
{
    internal interface IControler
    {
        void AddShape(ShapeType type);

        void RemoveShape(string id);

        void Move(string id, Point leftTop);

        void Resize(string id, Size size);
    }
}
