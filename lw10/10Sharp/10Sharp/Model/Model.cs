using _10Sharp.Model;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;


namespace _10Sharp.Model
{
    public enum ActionTypes
    {
        AddShape,
        RemoveShape,
        ResizeShape,
        MoveShape
    }

    public struct LastAction
    {
        public LastAction(string id, ActionTypes type)
        {
            m_id = id; m_type = type;
        }

        public string m_id;
        public ActionTypes m_type;
    }


    internal class Model : IObservable<LastAction>
    {
        public Model()
        {
            m_observers = new List<IObserver<LastAction>>();
            m_shapes = new Dictionary<string, Shape> ();
        }

        private List<IObserver<LastAction>> m_observers;
        private Dictionary <string, Shape> m_shapes;

        public IDisposable Subscribe(IObserver<LastAction> observer)
        {
            if (!m_observers.Contains(observer))
                m_observers.Add(observer);
            return new Unsubscriber(m_observers, observer);
        }

        private class Unsubscriber : IDisposable
        {
            private List<IObserver<LastAction>> m_observers;
            private IObserver<LastAction> m_observer;

            public Unsubscriber(List<IObserver<LastAction>> observers, IObserver<LastAction> observer)
            {
                this.m_observers = observers;
                this.m_observer = observer;
            }

            public void Dispose()
            {
                if (m_observer != null && m_observers.Contains(m_observer))
                    m_observers.Remove(m_observer);
            }
        }

        public void Resize(string id, Size size)
        {
            //добавить проверку на наличие
            m_shapes[id].m_size = size;
            //вынести
            foreach(var observer in m_observers)
            {
                observer.OnNext(new LastAction(id, ActionTypes.ResizeShape));
            }
        }

        public void Remove(string id)
        {
            m_shapes.Remove(id);
            foreach(var observer in m_observers)
            {
                observer.OnNext(new LastAction(id, ActionTypes.RemoveShape));
            }
        }

        public void Move(string id, Point leftTop)
        {
            m_shapes[id].m_leftTop = leftTop;
            foreach(var observer in m_observers)
            {
                observer.OnNext(new LastAction(id, ActionTypes.MoveShape));
            }
        }

        public void Add(ShapeType type)
        {
            RandomStringGenerator randomStringGenerator = new RandomStringGenerator();

            string id = randomStringGenerator.GenerateId(20);

            m_shapes[id] = new Shape(type);

            foreach (var observer in m_observers)
            {
                observer.OnNext(new LastAction(id, ActionTypes.AddShape));
            }
        }

        public Shape GetShape(string id)
        {
            return m_shapes[id];
        }
    }
}
