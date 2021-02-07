class Post():
    def __init__(self, message, to, fro, message_type="text"):
        self.message = message
        self.type = message_type
        self.to = to
        self.fro = fro


class User():
    def __init__(self, u_id):
        self.u_id = u_id
        self.groups = []
        self.contacts = []
        self.posts = []
        self.messages = []

    def add_contacts(self, users):
        self.contacts.append(users)

    def add_groups(self, group):
        self.groups.append(group)

    def post(self, message):
        self.posts.append(message)

    def receive(self, message):
        self.messages.append(message)


class Group():
    def __init__(self, u_id):
        self.u_id = u_id
        self.users = {}
        self.messages = []

    def add_contacts(self, user):
        self.users[user.u_id] = user
        self.users[user.u_id].add_groups(self.u_id)

    def add_message(self, message):
        self.messages.append(message)

    def receive(self, message):
        self.add_message(message)
        for user in self.users.values():
            if(user.u_id != message.fro):
                user.receive(message)


class Network():
    def __init__(self, filename):
        self.filename = filename
        self.file = None
        self.nodes = {}
        self.messages = []
        
    def parse(self):
        self.file = open(self.filename, mode="r")
        suff = None

        for line in self.file:
            temp = line.strip('\n')
            if temp.find('#users') != -1:
                suff = "User"
            elif temp.find('#groups') != -1:
                suff = "Group"
            elif len(temp) >= 1 and suff is not None:
                fields = temp.strip('<>').split(': ')
                u_id = fields[0]
                members = fields[1].split(", ")
                
                if suff == "User":
                    node = User(suff+u_id)
                    for member in members:
                        node.add_contacts("User"+member)
                    self.nodes[suff+u_id] = node
                elif suff == "Group":
                    node = Group(suff+u_id)
                    for member in members:
                        node.add_contacts(self.nodes["User"+member])
                    self.nodes[suff+u_id] = node

        self.file.close()

    def message(self, message):
        self.messages.append(message)
        self.nodes[message.fro].post(message)
        self.nodes[message.to].receive(message)

    def read_messages(self, filename):
        m_file = open(filename, mode='r')
        for line in m_file:
            foo = line.strip('\n<>')
            if len(foo) >= 1:
                bar = foo.split(': ')
                message = Post(bar[1], bar[3], bar[0], bar[2])
                self.message(message)
        m_file.close()

    def write_messages(self, filename):
        m_file = open(filename, mode='w')
        for foo in self.messages:
            m_file.write("<{}: {}: {}: {}>\n".format(
                foo.fro, foo.message, foo.type, foo.to))
