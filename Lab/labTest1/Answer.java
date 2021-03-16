import java.util.*;

class User{
    public String id;
    public ArrayList<String> messages;
    public HashSet<String> contacts;
    User(Scanner obj){
        id = new String();
        messages = new ArrayList<String>();
        contacts = new HashSet<String>();
        System.out.println("Enter Phone no");
        id = obj.nextLine();
    }
    public void addContact(Scanner obj){
        System.out.println("Enter Contact no.");
        String phone = obj.nextLine();
        if(!contacts.contains(phone)){
            contacts.add(phone);
            System.out.println("Contact Added");
        }
        else{
            System.out.println("Contact Already Present");
        }
        return;
    }

    public void receiveMessage(String x){
        messages.add(x);
    }

    public void printMessages(){
        System.out.println("Messages:");
        for(int i = 0;i<messages.size();i++){
            System.out.println(messages.get(i));
        }
    }

    public String sendMessage(Scanner obj){
        System.out.println("Enter Message");
        String temp = obj.nextLine();
        System.out.println("Enter Message setting");
        String setting = obj.nextLine();
        if(setting.equalsIgnoreCase("private")){
            return String.format(temp + ":" +"private");
        }
        else
            return String.format(temp + ":" +"public");
    }
}

class Group{
    public HashMap<String,User> users;
    public String name;
    Group(Scanner obj){
        users = new HashMap<String,User>();
        name = new String();
        System.out.println("Enter Group Name");
        name = obj.nextLine();

    }
    public void addUser(User x){
        if(!users.containsKey(x.id)){
            users.put(x.id, x);
        }
    }
    public void postMessage(String from,String message){
        User f = users.get(from);
        boolean setting = message.endsWith(":private");
        if(setting){
            for(String to:f.contacts){
                User temp = users.get(to);
                temp.receiveMessage(message.substring(0,message.length()-String.format(":private").length()));
            }
        }
        else
        {
            for(String to:users.keySet()){
                User temp = users.get(to);
                temp.receiveMessage(message.substring(0,message.length()-String.format(":private").length()));
            }
        }
    }
}




public class Answer {
    public HashMap<String,User> clients;
    public HashMap<String,Group> groups;

    Answer(){
        clients = new HashMap<String,User>();
        groups = new HashMap<String,Group>();
    }
    public static void main(String[] args) {
        Answer syst = new Answer();
        Scanner obj = new Scanner(System.in);
        System.out.println("Hello");
        int flag = -1;
        while (flag != 0) {
            System.out.println("\n*********MENU DRIVEN PROGRAM*********");
            System.out.println("Enter 1 for Creating User");
            System.out.println("Enter 2 for Creating a Group");
            System.out.println("Enter 3 for adding contact to a user");
            System.out.println("Enter 3 for Adding User to Group");
            System.out.println("Enter 4 to post a message");
            System.out.println("Enter 5 to see all messages");
            flag = Integer.parseInt(obj.nextLine());
            boolean check;
            switch (flag) {
                case 1:
                    User l = new User(obj);
                    syst.clients.put(l.id,)


            }
        obj.close();
    }
}
