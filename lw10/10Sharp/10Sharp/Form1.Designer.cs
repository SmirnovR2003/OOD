

using _10Sharp.Model;
using System;
using System.Collections.Generic;
using System.Windows.Forms;

namespace _10Sharp
{
    partial class Form1 : Form , IObserver<LastAction>
    {

        public Form1(Model.Model model, Controler.IControler controler)
        {
            InitializeComponent();
            m_model = model;
            m_controler = controler;
            m_model.Subscribe(this);
            m_dragAndDrop = new SDragAndDrop();
            m_resize = new SResize();
            m_observActions = new Dictionary<Model.ActionTypes, Delegate> 
            {
                {Model.ActionTypes.AddShape, new Action<string>(CreateShape)},
                {Model.ActionTypes.RemoveShape, new Action<string>(RemoveShape)},
                {Model.ActionTypes.MoveShape, new Action<string>(MoveShape)},
                {Model.ActionTypes.ResizeShape, new Action<string>(ResizeShape)},
            };
        }

        /// <summary>
        /// Обязательная переменная конструктора.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Освободить все используемые ресурсы.
        /// </summary>
        /// <param name="disposing">истинно, если управляемый ресурс должен быть удален; иначе ложно.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Код, автоматически созданный конструктором форм Windows

        /// <summary>
        /// Требуемый метод для поддержки конструктора — не изменяйте 
        /// содержимое этого метода с помощью редактора кода.
        /// </summary>
        private void InitializeComponent()
        {
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(Form1));
            this.canvas = new System.Windows.Forms.Panel();
            this.menuStrip = new System.Windows.Forms.MenuStrip();
            this.addShapeToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.triangleToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.rectangleToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.ellipseToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.removeShapeToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.choosenShapeToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.resizeSquare = new System.Windows.Forms.PictureBox();
            this.ellipse = new System.Windows.Forms.PictureBox();
            this.rectangle = new System.Windows.Forms.PictureBox();
            this.triangle = new System.Windows.Forms.PictureBox();
            this.menuStrip.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.resizeSquare)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.ellipse)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.rectangle)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.triangle)).BeginInit();
            this.SuspendLayout();
            // 
            // canvas
            // 
            this.canvas.Anchor = ((System.Windows.Forms.AnchorStyles)((((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Bottom) 
            | System.Windows.Forms.AnchorStyles.Left) 
            | System.Windows.Forms.AnchorStyles.Right)));
            this.canvas.BackColor = System.Drawing.SystemColors.ButtonHighlight;
            this.canvas.BorderStyle = System.Windows.Forms.BorderStyle.FixedSingle;
            this.canvas.Location = new System.Drawing.Point(12, 31);
            this.canvas.Margin = new System.Windows.Forms.Padding(0);
            this.canvas.Name = "canvas";
            this.canvas.Size = new System.Drawing.Size(776, 407);
            this.canvas.TabIndex = 0;
            this.canvas.MouseDown += new System.Windows.Forms.MouseEventHandler(this.canvas_MouseDown);
            // 
            // menuStrip
            // 
            this.menuStrip.ImageScalingSize = new System.Drawing.Size(20, 20);
            this.menuStrip.Items.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.addShapeToolStripMenuItem,
            this.removeShapeToolStripMenuItem});
            this.menuStrip.Location = new System.Drawing.Point(0, 0);
            this.menuStrip.Name = "menuStrip";
            this.menuStrip.Size = new System.Drawing.Size(800, 28);
            this.menuStrip.TabIndex = 1;
            this.menuStrip.Text = "menuStrip";
            // 
            // addShapeToolStripMenuItem
            // 
            this.addShapeToolStripMenuItem.DropDownItems.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.triangleToolStripMenuItem,
            this.rectangleToolStripMenuItem,
            this.ellipseToolStripMenuItem});
            this.addShapeToolStripMenuItem.Name = "addShapeToolStripMenuItem";
            this.addShapeToolStripMenuItem.Size = new System.Drawing.Size(92, 24);
            this.addShapeToolStripMenuItem.Text = "AddShape";
            // 
            // triangleToolStripMenuItem
            // 
            this.triangleToolStripMenuItem.Name = "triangleToolStripMenuItem";
            this.triangleToolStripMenuItem.Size = new System.Drawing.Size(158, 26);
            this.triangleToolStripMenuItem.Text = "Triangle";
            this.triangleToolStripMenuItem.Click += new System.EventHandler(this.triangleToolStripMenuItem_Click);
            // 
            // rectangleToolStripMenuItem
            // 
            this.rectangleToolStripMenuItem.Name = "rectangleToolStripMenuItem";
            this.rectangleToolStripMenuItem.Size = new System.Drawing.Size(158, 26);
            this.rectangleToolStripMenuItem.Text = "Rectangle";
            this.rectangleToolStripMenuItem.Click += new System.EventHandler(this.rectangleToolStripMenuItem_Click);
            // 
            // ellipseToolStripMenuItem
            // 
            this.ellipseToolStripMenuItem.Name = "ellipseToolStripMenuItem";
            this.ellipseToolStripMenuItem.Size = new System.Drawing.Size(158, 26);
            this.ellipseToolStripMenuItem.Text = "Ellipse";
            this.ellipseToolStripMenuItem.Click += new System.EventHandler(this.ellipseToolStripMenuItem_Click);
            // 
            // removeShapeToolStripMenuItem
            // 
            this.removeShapeToolStripMenuItem.DropDownItems.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.choosenShapeToolStripMenuItem});
            this.removeShapeToolStripMenuItem.Name = "removeShapeToolStripMenuItem";
            this.removeShapeToolStripMenuItem.Size = new System.Drawing.Size(118, 24);
            this.removeShapeToolStripMenuItem.Text = "RemoveShape";
            // 
            // choosenShapeToolStripMenuItem
            // 
            this.choosenShapeToolStripMenuItem.Name = "choosenShapeToolStripMenuItem";
            this.choosenShapeToolStripMenuItem.Size = new System.Drawing.Size(190, 26);
            this.choosenShapeToolStripMenuItem.Text = "ChoosenShape";
            this.choosenShapeToolStripMenuItem.Click += new System.EventHandler(this.choosenShapeToolStripMenuItem_Click);
            // 
            // resizeSquare
            // 
            this.resizeSquare.Image = ((System.Drawing.Image)(resources.GetObject("resizeSquare.Image")));
            this.resizeSquare.Location = new System.Drawing.Point(81, 63);
            this.resizeSquare.Margin = new System.Windows.Forms.Padding(0);
            this.resizeSquare.Name = "resizeSquare";
            this.resizeSquare.Size = new System.Drawing.Size(148, 126);
            this.resizeSquare.SizeMode = System.Windows.Forms.PictureBoxSizeMode.StretchImage;
            this.resizeSquare.TabIndex = 0;
            this.resizeSquare.TabStop = false;
            // 
            // ellipse
            // 
            this.ellipse.Anchor = ((System.Windows.Forms.AnchorStyles)((((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Bottom) 
            | System.Windows.Forms.AnchorStyles.Left) 
            | System.Windows.Forms.AnchorStyles.Right)));
            this.ellipse.BackColor = System.Drawing.Color.Transparent;
            this.ellipse.BackgroundImageLayout = System.Windows.Forms.ImageLayout.None;
            this.ellipse.Image = ((System.Drawing.Image)(resources.GetObject("ellipse.Image")));
            this.ellipse.Location = new System.Drawing.Point(345, 24);
            this.ellipse.Margin = new System.Windows.Forms.Padding(0);
            this.ellipse.Name = "ellipse";
            this.ellipse.Size = new System.Drawing.Size(10, 10);
            this.ellipse.SizeMode = System.Windows.Forms.PictureBoxSizeMode.StretchImage;
            this.ellipse.TabIndex = 1;
            this.ellipse.TabStop = false;
            // 
            // rectangle
            // 
            this.rectangle.Anchor = ((System.Windows.Forms.AnchorStyles)((((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Bottom) 
            | System.Windows.Forms.AnchorStyles.Left) 
            | System.Windows.Forms.AnchorStyles.Right)));
            this.rectangle.Image = ((System.Drawing.Image)(resources.GetObject("rectangle.Image")));
            this.rectangle.Location = new System.Drawing.Point(232, 221);
            this.rectangle.Margin = new System.Windows.Forms.Padding(0);
            this.rectangle.Name = "rectangle";
            this.rectangle.Size = new System.Drawing.Size(10, 10);
            this.rectangle.SizeMode = System.Windows.Forms.PictureBoxSizeMode.StretchImage;
            this.rectangle.TabIndex = 2;
            this.rectangle.TabStop = false;
            // 
            // triangle
            // 
            this.triangle.Anchor = ((System.Windows.Forms.AnchorStyles)((((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Bottom) 
            | System.Windows.Forms.AnchorStyles.Left) 
            | System.Windows.Forms.AnchorStyles.Right)));
            this.triangle.Image = ((System.Drawing.Image)(resources.GetObject("triangle.Image")));
            this.triangle.Location = new System.Drawing.Point(393, 168);
            this.triangle.Margin = new System.Windows.Forms.Padding(0);
            this.triangle.Name = "triangle";
            this.triangle.Size = new System.Drawing.Size(109, 124);
            this.triangle.SizeMode = System.Windows.Forms.PictureBoxSizeMode.StretchImage;
            this.triangle.TabIndex = 3;
            this.triangle.TabStop = false;
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(8F, 16F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.BackColor = System.Drawing.SystemColors.ControlDark;
            this.ClientSize = new System.Drawing.Size(800, 450);
            this.Controls.Add(this.canvas);
            this.Controls.Add(this.menuStrip);
            this.MainMenuStrip = this.menuStrip;
            this.Name = "Form1";
            this.Text = "App";
            this.TransparencyKey = System.Drawing.Color.Silver;
            this.DoubleBuffered = true;
            this.menuStrip.ResumeLayout(false);
            this.menuStrip.PerformLayout();
            ((System.ComponentModel.ISupportInitialize)(this.resizeSquare)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.ellipse)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.rectangle)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.triangle)).EndInit();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private struct SDragAndDrop
        {
            public bool start;
            public int startX;
            public int startY;
            public int lastX;
            public int lastY;
        };

        private struct SResize
        {
            public SDragAndDrop dragAndDrop;
            public int startW;
            public int startH;
        };

        private System.Windows.Forms.Panel canvas;
        private System.Windows.Forms.MenuStrip menuStrip;
        private System.Windows.Forms.ToolStripMenuItem addShapeToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem triangleToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem rectangleToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem ellipseToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem removeShapeToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem choosenShapeToolStripMenuItem;
        private System.Windows.Forms.PictureBox ellipse;
        private System.Windows.Forms.PictureBox resizeSquare;
        private System.Windows.Forms.PictureBox rectangle;
        private System.Windows.Forms.PictureBox triangle;


        private Model.Model m_model;
        private Controler.IControler m_controler;
        private SDragAndDrop m_dragAndDrop;
        private SResize m_resize;
        private Dictionary<Model.ActionTypes, Delegate> m_observActions;
        private string m_chosenShapeId;

        #region drag and drop

        void ShapeMouseMove(System.Object sender, System.Windows.Forms.MouseEventArgs e)
        {
            PictureBox picture = (System.Windows.Forms.PictureBox)sender;
            Panel panel = (System.Windows.Forms.Panel)picture.Parent;

            //вынести
            if (!m_dragAndDrop.start
            || MousePosition.X - m_dragAndDrop.startX + m_dragAndDrop.lastX < 0
            || MousePosition.Y - m_dragAndDrop.startY + m_dragAndDrop.lastY < 0
            || MousePosition.X - m_dragAndDrop.startX + m_dragAndDrop.lastX + panel.Size.Width > canvas.ClientSize.Width
            || MousePosition.Y - m_dragAndDrop.startY + m_dragAndDrop.lastY + panel.Size.Height > canvas.ClientSize.Height)
            {
                return;
            }

            panel.Location = new System.Drawing.Point(
                MousePosition.X - m_dragAndDrop.startX + m_dragAndDrop.lastX,
                MousePosition.Y - m_dragAndDrop.startY + m_dragAndDrop.lastY);
            canvas.Refresh();
        }

        void ShapeMouseDown(System.Object sender, System.Windows.Forms.MouseEventArgs e)
        {
            //сделать методы начала и конца dragAndDrop
            m_dragAndDrop.start = true;

            m_dragAndDrop.startX = MousePosition.X;
            m_dragAndDrop.startY = MousePosition.Y;

            PictureBox picture = (System.Windows.Forms.PictureBox)sender;
            Panel panel = (System.Windows.Forms.Panel)picture.Parent;

            m_dragAndDrop.lastX = panel.Location.X;
            m_dragAndDrop.lastY = panel.Location.Y;

            canvas_MouseDown(this, e);
            m_chosenShapeId = panel.Name;
            SelectShape(m_chosenShapeId);
        }

        void ShapeMouseUp(System.Object sender, System.Windows.Forms.MouseEventArgs e)
        {
            this.m_dragAndDrop.start = false;

            PictureBox picture = (System.Windows.Forms.PictureBox)sender;
            Panel panel = (System.Windows.Forms.Panel)picture.Parent;
            m_controler.Move(panel.Name, new Point( panel.Location.X, panel.Location.Y));
        }

        #endregion

        #region элементы меню

        private void ellipseToolStripMenuItem_Click(object sender, EventArgs e)
        {
            m_controler.AddShape(ShapeType.Ellipse);
        }

        private void rectangleToolStripMenuItem_Click(object sender, EventArgs e)
        {
            m_controler.AddShape(ShapeType.Rectangle);
        }

        private void triangleToolStripMenuItem_Click(object sender, EventArgs e)
        {
            m_controler.AddShape(ShapeType.Triangle);
        }

        private void choosenShapeToolStripMenuItem_Click(object sender, EventArgs e)
        {
            if(m_chosenShapeId != null)
                m_controler.RemoveShape(m_chosenShapeId);
        }

        #endregion

        #region методы ресайза

        void changeSizeSquareMouseDown(System.Object sender, System.Windows.Forms.MouseEventArgs e)
        {
            PictureBox picture = (System.Windows.Forms.PictureBox)sender;
            Panel panel = (System.Windows.Forms.Panel)picture.Parent;

            m_resize.dragAndDrop.start = true;
            m_resize.dragAndDrop.startX = MousePosition.X;
            m_resize.dragAndDrop.startY = MousePosition.Y;
            m_resize.dragAndDrop.lastX = panel.Location.X;
            m_resize.dragAndDrop.lastY = panel.Location.Y;
            m_resize.startW = panel.Size.Width;
            m_resize.startH = panel.Size.Height;
        }

        void changeSizeLeftTopSquareMouseMove(System.Object sender, System.Windows.Forms.MouseEventArgs e)
        {
            if(!m_resize.dragAndDrop.start)
            {
                return;
            }
            PictureBox picture = (System.Windows.Forms.PictureBox)sender;
            Panel panel = (System.Windows.Forms.Panel)picture.Parent;

            if(MousePosition.X - m_resize.dragAndDrop.startX + m_resize.dragAndDrop.lastX >= 0)
            {
                panel.Size = new System.Drawing.Size(
                    m_resize.startW - panel.Location.X + m_resize.dragAndDrop.lastX,
                    panel.Size.Height
                    );

                panel.Location = new System.Drawing.Point(
                    MousePosition.X - m_resize.dragAndDrop.startX + m_resize.dragAndDrop.lastX,
                    panel.Location.Y);
            }

            if(MousePosition.Y - m_resize.dragAndDrop.startY + m_resize.dragAndDrop.lastY >= 0)
            {
                panel.Size = new System.Drawing.Size(
                    panel.Size.Width,
                    m_resize.startH - panel.Location.Y + m_resize.dragAndDrop.lastY
                    );

                panel.Location = new System.Drawing.Point(
                    panel.Location.X,
                    MousePosition.Y - m_resize.dragAndDrop.startY + m_resize.dragAndDrop.lastY);
            }

            canvas.Refresh();
        }

        void changeSizeLeftBottomSquareMouseMove(System.Object sender, System.Windows.Forms.MouseEventArgs e)
        {
            if (!m_resize.dragAndDrop.start)
            {
                return;
            }
            PictureBox picture = (System.Windows.Forms.PictureBox)sender;
            Panel panel = (System.Windows.Forms.Panel)picture.Parent;

            if (MousePosition.X - m_resize.dragAndDrop.startX + m_resize.dragAndDrop.lastX >= 0)
            {
                panel.Size = new System.Drawing.Size(
                    m_resize.startW - panel.Location.X + m_resize.dragAndDrop.lastX,
                    panel.Size.Height
                    );

                panel.Location = new System.Drawing.Point(
                    MousePosition.X - m_resize.dragAndDrop.startX + m_resize.dragAndDrop.lastX,
                    panel.Location.Y);
            }

            if (panel.Location.Y + m_resize.startH + MousePosition.Y - m_resize.dragAndDrop.startY <= canvas.ClientSize.Height)
            {
                panel.Size = new System.Drawing.Size(
                    panel.Size.Width,
                    m_resize.startH + MousePosition.Y - m_resize.dragAndDrop.startY
                    );
            }
            canvas.Refresh();
        }

        void changeSizeRightBottomSquareMouseMove(System.Object sender, System.Windows.Forms.MouseEventArgs e)
        {
            if (!m_resize.dragAndDrop.start)
            {
                return;
            }
            PictureBox picture = (System.Windows.Forms.PictureBox)sender;
            Panel panel = (System.Windows.Forms.Panel)picture.Parent;

            if (panel.Location.X + m_resize.startW + MousePosition.X - m_resize.dragAndDrop.startX <= canvas.ClientSize.Width)
            {
                panel.Size = new System.Drawing.Size(
                    m_resize.startW + MousePosition.X - m_resize.dragAndDrop.startX,
                    panel.Size.Height
                    );
            }

            if (panel.Location.Y + m_resize.startH + MousePosition.Y - m_resize.dragAndDrop.startY <= canvas.ClientSize.Height)
            {
                panel.Size = new System.Drawing.Size(
                    panel.Size.Width,
                    m_resize.startH + MousePosition.Y - m_resize.dragAndDrop.startY
                    );
            }
            canvas.Refresh();
        }

        void changeSizeRightTopSquareMouseMove(System.Object sender, System.Windows.Forms.MouseEventArgs e)
        {
            if (!m_resize.dragAndDrop.start)
            {
                return;
            }
            PictureBox picture = (System.Windows.Forms.PictureBox)sender;
            Panel panel = (System.Windows.Forms.Panel)picture.Parent;

            if (panel.Location.X + m_resize.startW + MousePosition.X - m_resize.dragAndDrop.startX <= canvas.ClientSize.Width)
            {
                panel.Size = new System.Drawing.Size(
                    m_resize.startW + MousePosition.X - m_resize.dragAndDrop.startX,
                    panel.Size.Height
                    );
            }

            if (MousePosition.Y - m_resize.dragAndDrop.startY + m_resize.dragAndDrop.lastY >= 0)
            {
                panel.Size = new System.Drawing.Size(
                    panel.Size.Width,
                    m_resize.startH - MousePosition.Y + m_resize.dragAndDrop.startY
                    );

                panel.Location = new System.Drawing.Point(
                    panel.Location.X,
                    MousePosition.Y - m_resize.dragAndDrop.startY + m_resize.dragAndDrop.lastY);
            }
            canvas.Refresh();
        }

        void changeSizeSquareMouseUp(System.Object sender, System.Windows.Forms.MouseEventArgs e)
        {
            PictureBox picture = (System.Windows.Forms.PictureBox)sender;
            Panel panel = (System.Windows.Forms.Panel)picture.Parent;

            m_resize.dragAndDrop.start = false;
            m_controler.Move(panel.Name, new Point(panel.Location.X, panel.Location.Y));
            m_controler.Resize(panel.Name, new Size(panel.Size.Width, panel.Size.Height));
        }

        #endregion

        #region создание фигур

        public void CreateShape(string id)
        {
            System.Windows.Forms.Panel panel = CreatePanel(id);

            AddShapePicture(panel, m_model.GetShape(id).m_type);
            AddChangeSizeLeftTopSquare(panel, panel.Size);
            AddChangeSizeLeftBottomSquare(panel, panel.Size);
            AddChangeSizeRightBottomSquare(panel, panel.Size);
            AddChangeSizeRightTopSquare(panel, panel.Size);

            canvas.Controls.Add(panel);

            this.Refresh();
        }

        public System.Windows.Forms.Panel CreatePanel(string id)
        {
            System.Windows.Forms.Panel  panel = (new System.Windows.Forms.Panel());
            panel.Anchor = ((System.Windows.Forms.AnchorStyles)(System.Windows.Forms.AnchorStyles.Top 
                | System.Windows.Forms.AnchorStyles.Left));
            panel.ImeMode = System.Windows.Forms.ImeMode.NoControl;
            panel.Location = new System.Drawing.Point(0, 0);
            panel.Margin = new System.Windows.Forms.Padding(0);
            panel.Name = id;
            panel.RightToLeft = System.Windows.Forms.RightToLeft.Yes;
            panel.Size = new System.Drawing.Size(100, 100);
            panel.TabIndex = 1;
            panel.TabStop = false;
            panel.BackColor = System.Drawing.Color.Transparent;
            //panel->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &MyForm::Ellipse_Paint);

            return panel;
        }


        public void AddShapePicture(System.Windows.Forms.Panel panel, ShapeType type)
        {
            System.ComponentModel.ComponentResourceManager resources = (new System.ComponentModel.ComponentResourceManager(typeof(Form1)));

            System.Windows.Forms.PictureBox shape = (new System.Windows.Forms.PictureBox());

            if (type == ShapeType.Ellipse)
            {
                shape.Image = ((System.Drawing.Image)(resources.GetObject("ellipse.Image")));
            }
            else if (type == ShapeType.Rectangle)
            {
                shape.Image = ((System.Drawing.Image)(resources.GetObject("rectangle.Image")));
            }
            else if (type == ShapeType.Triangle)
            {
                shape.Image = ((System.Drawing.Image)(resources.GetObject("triangle.Image")));
            }

            shape.Location = new System.Drawing.Point(0, 0);
            shape.Name = "0";
            shape.Anchor = ((System.Windows.Forms.AnchorStyles)((((System.Windows.Forms.AnchorStyles.Top
                | System.Windows.Forms.AnchorStyles.Bottom)
                | System.Windows.Forms.AnchorStyles.Left)
                | System.Windows.Forms.AnchorStyles.Right)));
            shape.SizeMode = System.Windows.Forms.PictureBoxSizeMode.StretchImage;
            shape.Size = new System.Drawing.Size(100, 100);
            shape.TabIndex = 0;
            shape.TabStop = false;
            shape.BackColor = System.Drawing.Color.Transparent;
            shape.MouseMove += new System.Windows.Forms.MouseEventHandler(this.ShapeMouseMove);
            shape.MouseDown += new System.Windows.Forms.MouseEventHandler(this.ShapeMouseDown);
            shape.MouseUp += new System.Windows.Forms.MouseEventHandler(this.ShapeMouseUp);
            panel.Controls.Add(shape);
        }

        public void AddChangeSizeLeftTopSquare(System.Windows.Forms.Panel panel, System.Drawing.Size panelSize)
        {
            System.ComponentModel.ComponentResourceManager resources = (new System.ComponentModel.ComponentResourceManager(typeof(Form1)));

            System.Windows.Forms.PictureBox changeSizeLeftTopSquare = (new System.Windows.Forms.PictureBox());

            changeSizeLeftTopSquare.Anchor = ((System.Windows.Forms.AnchorStyles)(System.Windows.Forms.AnchorStyles.Top
                | System.Windows.Forms.AnchorStyles.Left));
            changeSizeLeftTopSquare.Cursor = System.Windows.Forms.Cursors.SizeNWSE;
            changeSizeLeftTopSquare.Image = ((System.Drawing.Image)(resources.GetObject("resizeSquare.Image")));
            changeSizeLeftTopSquare.Location = new System.Drawing.Point(0, 0);
            changeSizeLeftTopSquare.Margin = new System.Windows.Forms.Padding(0);
            changeSizeLeftTopSquare.Name = "1";
            changeSizeLeftTopSquare.Size = new System.Drawing.Size(10, 10);
            changeSizeLeftTopSquare.SizeMode = System.Windows.Forms.PictureBoxSizeMode.StretchImage;
            changeSizeLeftTopSquare.TabIndex = 2;
            changeSizeLeftTopSquare.TabStop = false;
            changeSizeLeftTopSquare.MouseDown += new System.Windows.Forms.MouseEventHandler(this.changeSizeSquareMouseDown);
            changeSizeLeftTopSquare.MouseMove += new System.Windows.Forms.MouseEventHandler(this.changeSizeLeftTopSquareMouseMove);
            changeSizeLeftTopSquare.MouseUp += new System.Windows.Forms.MouseEventHandler(this.changeSizeSquareMouseUp);
            panel.Controls.Add(changeSizeLeftTopSquare);
        }


        public void AddChangeSizeLeftBottomSquare(System.Windows.Forms.Panel panel, System.Drawing.Size panelSize)
        {
            System.ComponentModel.ComponentResourceManager resources = (new System.ComponentModel.ComponentResourceManager(typeof(Form1)));

            System.Windows.Forms.PictureBox changeSizeLeftBottomSquare = (new System.Windows.Forms.PictureBox());

            changeSizeLeftBottomSquare.Cursor = System.Windows.Forms.Cursors.SizeNESW;
            changeSizeLeftBottomSquare.Image = ((System.Drawing.Image)(resources.GetObject("resizeSquare.Image")));
            changeSizeLeftBottomSquare.Size = new System.Drawing.Size(10, 10);
            changeSizeLeftBottomSquare.Location = new System.Drawing.Point(
                0,
                panelSize.Height - changeSizeLeftBottomSquare.Size.Height);
            changeSizeLeftBottomSquare.Margin = new System.Windows.Forms.Padding(0);
            changeSizeLeftBottomSquare.Name = "2";
            changeSizeLeftBottomSquare.SizeMode = System.Windows.Forms.PictureBoxSizeMode.StretchImage;
            changeSizeLeftBottomSquare.TabIndex = 2;
            changeSizeLeftBottomSquare.TabStop = false;
            changeSizeLeftBottomSquare.Anchor = ((System.Windows.Forms.AnchorStyles)(System.Windows.Forms.AnchorStyles.Bottom
                | System.Windows.Forms.AnchorStyles.Left));
            changeSizeLeftBottomSquare.MouseDown += new System.Windows.Forms.MouseEventHandler(this.changeSizeSquareMouseDown);
            changeSizeLeftBottomSquare.MouseMove += new System.Windows.Forms.MouseEventHandler(this.changeSizeLeftBottomSquareMouseMove);
            changeSizeLeftBottomSquare.MouseUp += new System.Windows.Forms.MouseEventHandler(this.changeSizeSquareMouseUp);
            panel.Controls.Add(changeSizeLeftBottomSquare);
        }

        public void AddChangeSizeRightBottomSquare(System.Windows.Forms.Panel panel, System.Drawing.Size panelSize)
        {
            System.ComponentModel.ComponentResourceManager resources = (new System.ComponentModel.ComponentResourceManager(typeof(Form1)));

            System.Windows.Forms.PictureBox changeSizeRightBottomSquare = (new System.Windows.Forms.PictureBox());

            changeSizeRightBottomSquare.Cursor = System.Windows.Forms.Cursors.SizeNWSE;
            changeSizeRightBottomSquare.Image = ((System.Drawing.Image)(resources.GetObject("resizeSquare.Image")));
            changeSizeRightBottomSquare.Size = new System.Drawing.Size(10, 10);
            changeSizeRightBottomSquare.Location = new System.Drawing.Point(
                panelSize.Width - changeSizeRightBottomSquare.Size.Width,
                panelSize.Height - changeSizeRightBottomSquare.Size.Height);
            changeSizeRightBottomSquare.Margin = new System.Windows.Forms.Padding(0);
            changeSizeRightBottomSquare.Name = "3";
            changeSizeRightBottomSquare.SizeMode = System.Windows.Forms.PictureBoxSizeMode.StretchImage;
            changeSizeRightBottomSquare.TabIndex = 2;
            changeSizeRightBottomSquare.TabStop = false;
            changeSizeRightBottomSquare.Anchor = ((System.Windows.Forms.AnchorStyles)(System.Windows.Forms.AnchorStyles.Bottom
                | System.Windows.Forms.AnchorStyles.Right));
            changeSizeRightBottomSquare.MouseDown += new System.Windows.Forms.MouseEventHandler(this.changeSizeSquareMouseDown);
            changeSizeRightBottomSquare.MouseMove += new System.Windows.Forms.MouseEventHandler(this.changeSizeRightBottomSquareMouseMove);
            changeSizeRightBottomSquare.MouseUp += new System.Windows.Forms.MouseEventHandler(this.changeSizeSquareMouseUp);
            panel.Controls.Add(changeSizeRightBottomSquare);
        }

        public void AddChangeSizeRightTopSquare(System.Windows.Forms.Panel panel, System.Drawing.Size panelSize)
        {
            System.ComponentModel.ComponentResourceManager resources = (new System.ComponentModel.ComponentResourceManager(typeof(Form1)));

            System.Windows.Forms.PictureBox changeSizeRightTopSquare = (new System.Windows.Forms.PictureBox());
            changeSizeRightTopSquare.Cursor = System.Windows.Forms.Cursors.SizeNESW;
            changeSizeRightTopSquare.Image = ((System.Drawing.Image)(resources.GetObject("resizeSquare.Image")));

            changeSizeRightTopSquare.Size = new System.Drawing.Size(10, 10);
            changeSizeRightTopSquare.Location = new System.Drawing.Point(
                panelSize.Width - changeSizeRightTopSquare.Size.Width,
                0);
            changeSizeRightTopSquare.Margin = new System.Windows.Forms.Padding(0);
            changeSizeRightTopSquare.Name = "4";
            changeSizeRightTopSquare.SizeMode = System.Windows.Forms.PictureBoxSizeMode.StretchImage;
            changeSizeRightTopSquare.TabIndex = 2;
            changeSizeRightTopSquare.TabStop = false;
            changeSizeRightTopSquare.Anchor = ((System.Windows.Forms.AnchorStyles)(System.Windows.Forms.AnchorStyles.Top
                | System.Windows.Forms.AnchorStyles.Right));
            changeSizeRightTopSquare.MouseDown += new System.Windows.Forms.MouseEventHandler(this.changeSizeSquareMouseDown);
            changeSizeRightTopSquare.MouseMove += new System.Windows.Forms.MouseEventHandler(this.changeSizeRightTopSquareMouseMove);
            changeSizeRightTopSquare.MouseUp += new System.Windows.Forms.MouseEventHandler(this.changeSizeSquareMouseUp);

            panel.Controls.Add(changeSizeRightTopSquare);
        }

        #endregion

        #region observer методы

        public void RemoveShape(string id)
        {
            canvas.Controls.RemoveByKey(id);
            m_chosenShapeId = null;
        }

        private void ResizeShape(string id)
        {
            Size newSize = m_model.GetShape(id).m_size;
            Point newPoint = m_model.GetShape(id).m_leftTop;

            canvas.Controls[id].Size = new System.Drawing.Size(newSize.width, newSize.height);
            canvas.Controls[id].Location = new System.Drawing.Point(newPoint.x, newPoint.y);
        }

        private void MoveShape(string id)
        {
            Point newPoint = m_model.GetShape(id).m_leftTop;
            canvas.Controls[id].Location = new System.Drawing.Point(newPoint.x, newPoint.y);
        }

        public void OnNext(LastAction value)
        {
            this.m_observActions[value.m_type].DynamicInvoke(value.m_id);
            canvas.Refresh();
        }

        public void OnError(Exception error)
        {
            throw new NotImplementedException();
        }

        public void OnCompleted()
        {
            throw new NotImplementedException();
        }

        #endregion

        private void canvas_MouseDown(object sender, MouseEventArgs e)
        {
            //не вынасить на передний план фигуры, но выносить рамку
            if(m_chosenShapeId != null)
            {
                canvas.Controls[m_chosenShapeId].Controls["0"].BringToFront();
                ((Panel)canvas.Controls[m_chosenShapeId]).BorderStyle = BorderStyle.None;
                m_chosenShapeId = null;
                canvas.Refresh();

            }
        }

        private void SelectShape(string id)
        {
            ((Panel)canvas.Controls[id]).BorderStyle = BorderStyle.FixedSingle;
            canvas.Controls[id].Controls["0"].SendToBack();
            canvas.Controls[id].BringToFront();
            canvas.Refresh();
        }
    }
}

