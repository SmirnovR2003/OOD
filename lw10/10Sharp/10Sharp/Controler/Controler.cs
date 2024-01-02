
namespace _10Sharp.Controler
{
    internal class Controler : IControler
    {
        public Controler(Model.Model model)
        { m_model = model; }

        public void AddShape(ShapeType type)
        {
            m_model.Add(type);
        }

        public void RemoveShape(string id)
        {
            m_model.Remove(id);
        }

        public void Move(string id, Point leftTop)
        {
            m_model.Move(id, leftTop);
        }

        public void Resize(string id, Size size)
        {
            m_model.Resize(id, size);
        }

        private Model.Model m_model;
    }
}
