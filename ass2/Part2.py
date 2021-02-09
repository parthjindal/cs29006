from Network import *
from tkinter import *
from tkinter import filedialog
import tkinter.font as font
from PIL import ImageTk, Image
import tkinter as tk
from tkinter import messagebox


class UserFrame(Frame):
    def __init__(self, master=None, network=None):
        super().__init__(master=master, bg="#EAF6F6")
        self.master = master
        self.network = network
        self.label1 = Label(master=self, text="Select User")
        self.userId = StringVar(value="User")
        self.userId.trace("w", self.updateText)
        self.userIds = [x for x in network.nodes.keys()
                        if x.find("Group") == -1]
        self.droplist = OptionMenu(self, self.userId, *self.userIds)
        self.contacts = Text(master=self,)
        self.groups = Text(master=self)
        self.rFrame = Receive(master)
        self.pFrame = PostMessages(master, network)

    def updateText(self, *args):
        self.contacts.configure(state=NORMAL)
        self.groups.configure(state=NORMAL)
        self.contacts.delete(1.0, END)
        self.groups.delete(1.0, END)
        user = self.network.nodes[self.userId.get()]
        for contact in user.contacts:
            self.contacts.insert(END, contact+"\n")
        for group in user.groups:
            self.groups.insert(END, group+"\n")

        self.contacts.configure(state=DISABLED)
        self.groups.configure(state=DISABLED)
        self.rFrame.update(user.messages)
        self.pFrame.update(user.contacts + user.groups, user.u_id)

    def place(self):
        self.label1.grid(row=0, column=0, columnspan=2,
                         pady=10, padx=10, sticky="nswe")
        self.droplist.grid(row=1, column=0, columnspan=2,
                           pady=10, padx=20, sticky="nsew")
        self.contacts.grid(row=2, column=0)
        self.groups.grid(row=2, column=1)
        self.grid(row=0, column=0, sticky=S+N+E+W)
        self.master.grid_columnconfigure(0, weight=1)
        self.master.grid_rowconfigure(0, weight=1)
        self.pFrame.place()
        self.rFrame.place()

    def style(self):
        self.droplist.configure(width=8, height=1, background="#EAF6F6", fg="black", font=(
            "Serif", "15"), borderwidth=2, relief="solid")
        self.label1.configure(font=(
            "Serif", "20", "bold"), height=2, width=15, bg="#EAF6F6", fg="black")
        self.contacts.configure(width=10, height=20, bg="#EAF6F6", fg="black", font=(
            "Serif", "10"), borderwidth=2, relief="solid")
        self.groups.configure(width=10, height=20, bg="#EAF6F6", fg="black", font=(
            "Serif", "10"), borderwidth=2, relief="solid")


class Receive(Frame):
    def __init__(self, master=None):
        super().__init__(master=master, background="#EAF6F6")
        self.master = master
        self.label = Label(master=self, text="Inbox")
        self.messages = []
        self.m_no = 0
        self.textBox = Text(master=self, state=DISABLED)
        self.prevButton = Button(
            self, text="<<", command=lambda: self.iterate_m(-1))
        self.nextButton = Button(
            self, text=" >>", command=lambda: self.iterate_m(1))
        self.image = None
        self.style()

    def iterate_m(self, flag, *args):
        if ((self.m_no + flag) <= 0) or ((self.m_no+flag) > len(self.messages)):
            return
        self.m_no += flag
        message = self.messages[self.m_no-1]
        if(message.type == "text"):
            temp = message.message.replace("\\n", "\n")
            self.textBox.configure(state=NORMAL)
            self.textBox.delete(1.0, END)
            self.textBox.insert(END, "From: {}\nMessage: {}\n".format(
                message.fro, temp))
            self.textBox.configure(state=DISABLED)
        elif(message.type == "image"):
            self.textBox.configure(state=NORMAL)
            self.textBox.delete(1.0, END)
            self.textBox.insert(END, "From: {}\nMessage:".format(message.fro))
            self.image = ImageTk.PhotoImage(
                Image.open(message.message).resize((300, 350)))
            self.textBox.image_create(END, image=self.image)
            self.textBox.configure(state=DISABLED)

    def place(self):
        self.label.grid(row=0, column=0, columnspan=2,
                        pady=10, padx=10, sticky="nswe")
        self.textBox.grid(row=1, column=0, columnspan=2,
                          pady=10, padx=10, sticky="nsew")
        self.prevButton.grid(row=2, column=0)
        self.nextButton.grid(row=2, column=1)
        self.grid(row=0, column=1, sticky=S+N+E+W)
        self.master.grid_columnconfigure(1, weight=1)

    def style(self):
        self.label.configure(font=(
            "Serif", "20", "bold"), height=2, width=15, bg="#EAF6F6", fg="black")
        self.textBox.configure(width=15, height=23, bg="#EAF6F6", borderwidth=2, relief="solid", font=(
            "Serif", "10",))
        self.prevButton.configure(bg="#EAF6F6", borderwidth=2, relief="solid", font=(
            "Serif", "10",))
        self.nextButton.configure(bg="#EAF6F6", borderwidth=2, relief="solid", font=(
            "Serif", "10",))

    def update(self, messages):
        self.messages = messages
        self.m_no = 0
        self.textBox.configure(state=NORMAL)
        self.textBox.delete(1.0, END)
        self.textBox.configure(state=DISABLED)
        self.iterate_m(1)


class PostMessages(Frame):
    def __init__(self, master=None, network=None):
        super().__init__(master=master, background="#EAF6F6")
        self.master = master
        self.network = network
        self.textBox = Text(self, state=NORMAL)
        self.label = Label(self, text="Post Message")
        self.m_type = "text"
        self.postButton = Button(self, text="Post", command=self.postMessage)
        self.imageButton = Button(
            self, text="Select Image", command=self.selectImage)
        self.to = StringVar(value="User")
        self.fro = None
        choices = ('',)
        self.dropList = OptionMenu(self, self.to, *choices)
        self.style()

    def selectImage(self):
        self.filename = str(filedialog.askopenfilename(
            initialdir="/home/parth/Pictures", title="Select a file"))
        self.image = ImageTk.PhotoImage(
            Image.open(self.filename).resize((300, 350)))
        self.textBox.configure(state=NORMAL)
        self.textBox.delete(1.0, END)
        self.textBox.image_create(END, image=self.image)
        self.m_type = "image"

    def postMessage(self):
        if self.m_type != "image" and len(self.textBox.get(1.0, END)) < 1:
            return
        if self.m_type == "image" and len(self.textBox.image_names()) < 1:
            self.m_type = "text"

        if self.m_type == "text":
            message = Post(self.textBox.get(1.0, END),
                           self.to.get(), self.fro, self.m_type)
            message.message = message.message.replace("\n", "\\n")
            self.network.message(message)
        if self.m_type == "image":
            print(self.textBox.get(1.0, END))
            message = Post(self.filename, self.to.get(), self.fro, self.m_type)
            self.network.message(message)

        self.textBox.delete(1.0, END)
        self.m_type = "text"
        self.to.set("User")
        messagebox.showinfo(title="Done", message="Posted")

    def update(self, contacts, fro):
        menu = self.dropList["menu"]
        menu.delete(0, "end")
        for contact in contacts:
            menu.add_command(
                label=contact, command=tk._setit(self.to, contact))
        self.to.set("User")
        self.fro = fro
        self.textBox.delete(1.0, END)
        self.m_type = "text"

    def place(self):
        self.label.grid(row=0, column=0, columnspan=2, pady=10, sticky="nsew")
        self.dropList.grid(row=1, column=0, columnspan=2,
                           pady=10, sticky="nsew")
        self.textBox.grid(row=2, column=0, columnspan=2, sticky="nsew")
        self.postButton.grid(row=3, column=0, pady=10)
        self.imageButton.grid(row=3, column=1, pady=10)
        self.grid(row=0, column=2, sticky="nsew", padx=15)
        self.master.grid_columnconfigure(2, weight=1)

    def style(self):
        self.label.configure(font=(
            "Serif", "20", "bold"), height=2, width=15, bg="#EAF6F6", fg="black")
        self.textBox.configure(width=20, height=20,
                               bg="#EAF6F6", relief="solid", borderwidth=2)
        self.dropList.configure(bg="#EAF6F6", height=1, font=(
            "Serif", "15"), relief="solid")
        self.postButton.configure(bg="#EAF6F6", height=1, font=(
            "Serif", "10"), relief="solid", borderwidth=2)
        self.imageButton.configure(bg="#EAF6F6", height=1, font=(
            "Serif", "10"), relief="solid", borderwidth=2)


def main():
    root = Tk()
    root.title("Social Network")
    root.configure(bg="#EAF6F6")
    network = Network("social.txt")

    def on_closing():
        network.write_messages("messages.txt")
        root.destroy()

    network.parse()
    network.read_messages("messages.txt")
    frame = UserFrame(master=root, network=network)
    frame.style()
    frame.place()
    root.protocol("WM_DELETE_WINDOW", on_closing)
    root.mainloop()


if __name__ == "__main__":
    main()
