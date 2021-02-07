from tkinter import *
from ast import literal_eval
import numpy as np
from matplotlib.backends.backend_tkagg import FigureCanvasTkAgg, NavigationToolbar2Tk
from matplotlib.figure import Figure
import matplotlib.pyplot as plt


class LeftFrame(Frame):
    def __init__(self, master=None, rFrame=None):
        super().__init__(master=master, width=500, height=600, background="white")
        self.master = master
        master.grid_columnconfigure(0, weight=1)
        master.grid_rowconfigure(0, weight=1)
        self.label1 = Label(self, text="Expression (variable x): ", font=(20))
        self.label2 = Label(self, text="Variable Range(a,b): ", font=(20))
        self.exprBox = Text(self, width=33, height=2, padx=10, pady=20)
        self.rangeBox = Text(self, width=33, height=2, padx=10, pady=20)
        self.plotButton = Button(self, text="Plot", command=self.plot)
        self.clearButton = Button(self, text="Clear", command=self.clearText)
        self.exitButton = Button(self, text="Exit", command=exit)
        self.plotter = rFrame

    def plot(self):
        expr = self.exprBox.get(1.0, END)
        expr = expr.replace("^", "**")
        expr = expr.strip("\n")
        rangeTuple = self.rangeBox.get(1.0, END)
        a_b = rangeTuple.strip("\n()").split(",")
        a, b = float(a_b[0]), float(a_b[1])
        x = np.linspace(a, b, 100)
        y = eval(expr)
        if (type(y)):
            y = np.full((100,),y)
        fig = plt.figure(figsize=(4, 4))
        plt.plot(x, y)
        self.plotter.create(fig)

    def clearText(self):
        self.exprBox.delete(1.0, END)
        self.rangeBox.delete(1.0, END)
        self.plotter.clear()

    def place(self):
        self.grid(row=0, column=0, sticky=S+N+E+W)
        self.grid_propagate(0)
        self.label1.grid(row=0, column=0, columnspan=3)
        self.exprBox.grid(row=1, column=0, columnspan=3)
        self.label2.grid(row=2, column=0, columnspan=3)
        self.rangeBox.grid(row=3, column=0, columnspan=3)
        self.clearButton.grid(row=4, column=0)
        self.plotButton.grid(row=4, column=1)
        self.exitButton.grid(row=4, column=2)


class RightFrame(Frame):
    def __init__(self, master=None):
        super().__init__(master, width=600, height=600, background="white")
        self.master = master
        self.grid(row=0, column=1, sticky=S+N+E+W)
        self.grid_propagate(0)
        master.grid_columnconfigure(1, weight=1)

    def create(self, fig):
        self.canvas = FigureCanvasTkAgg(master=self, figure=fig)
        self.canvas.draw()
        self.canvas.get_tk_widget().configure(width = 500,height = 350)
        self.canvas.get_tk_widget().grid(row=0, column=0, sticky=S+N+W+E)
        self.navBar = NavigationToolbar2Tk(self.canvas, self)
        self.navBar.configure(width = 500,height = 100,padx = 30,pady = 20)
        self.navBar.grid(row=1, column=0)

    def clear(self):
        self.canvas.get_tk_widget().delete("all")
        self.navBar.update()


root = Tk()
rFrame = RightFrame(root)
x = LeftFrame(root, rFrame)
x.place()
root.mainloop()
