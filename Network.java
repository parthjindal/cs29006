import java.util.*;
import java.time.*;
import java.awt.geom.*;

abstract class Node {
    protected int id;
    protected String name;
    protected Date createTime;
    static int count = 0;
    public ArrayList<String> contents;
    public HashSet<String> originalContents;
    public Map<Node, String> link;

    Node(Scanner obj) {
        originalContents = new HashSet<String>();
        contents = new ArrayList<String>();
        link = new HashMap<Node, String>();
        createTime = new Date();
        id = count;
        count++;
        setName(obj);
    }

    abstract public boolean checkLinkSanity(Node x, String relation);

    @Override
    public String toString() {
        String returnString = "Name: " + getName() + "\nID:" + this.getID() + "\nType: " + this.getClass().getName()
                + "\n";
        return returnString;
    }

    public String getName() {
        return this.name;
    }

    public int getID() {
        return this.id;
    }

    public void setName(Scanner obj) {
        System.out.print("Enter Name:");
        name = obj.nextLine();
    }

    public boolean insertLink(Node x, String relation) {
        if (checkLinkSanity(x, relation) == false) {
            return false;
        }
        link.put(x, relation);
        return true;
    }

    public void postContent(String content, int repost) {
        int index = -1;
        if (repost == 0) {
            originalContents.add(content);
            contents.add(content);
            System.out.println("Post created");
            return;
        } else {
            index = contents.indexOf(content);
            contents.add(contents.get(index));
            System.out.println("Reposted");
        }
    }

};

class Individual extends Node {
    private LocalDate birthDate;

    Individual(Scanner obj) {
        super(obj);
        setBirthdate(obj);
    }

    public LocalDate getBirthDate() {
        return this.birthDate;
    }

    public void setBirthdate(Scanner obj) {
        System.out.print("Enter DOB(yyyy-mm-dd)");
        String dateString = obj.nextLine();
        birthDate = LocalDate.parse(dateString);
    }

    public boolean checkLinkSanity(Node x, String relation) {
        if (x.getClass().getName().matches("Group|Organisation") && relation.matches("member")) {
            return true;
        } else if (x.getClass().getName().matches("Business") && relation.matches("customer|owner")) {
            return true;
        }
        return false;
    }

    @Override
    public String toString() {
        String returnString = super.toString() + "Date of Birth: " + this.getBirthDate() + "\n";
        return returnString;
    }

};

class Group extends Node {

    Group(Scanner obj) {
        super(obj);
    }

    public boolean checkLinkSanity(Node x, String relation) {
        if (x.getClass().getName().matches("Individual") && relation.matches("member"))
            return true;
        return false;
    }

    @Override
    public String toString() {
        return super.toString();
    }
}

class Business extends Group {
    protected Point2D.Double location;

    Business(Scanner obj) {
        super(obj);
        location = new Point2D.Double();
        setLocation(obj);
    }

    public void setLocation(Scanner obj) {
        System.out.print("Enter Location(X Y)");
        location.x = obj.nextDouble();
        location.y = obj.nextDouble();
        obj.nextLine();
    }

    public Point2D.Double getLocation() {
        return location;
    }

    @Override
    public boolean checkLinkSanity(Node x, String relation) {
        if (x.getClass().getName().matches("Group") && relation.matches("member")) {
            return true;
        } else if (x.getClass().getName().matches("Individual") && relation.matches("customer|owner")) {
            return true;
        }
        return false;
    }

    @Override
    public String toString() {
        String returnString = super.toString() + "Location: "
                + String.format("(%.2f,%.2f)", this.getLocation().getX(), this.getLocation().getY());
        return returnString;
    }

};

class Organisation extends Business {
    Organisation(Scanner obj) {
        super(obj);
    }

    @Override
    public boolean checkLinkSanity(Node x, String relation) {
        if (x.getClass().getName().matches("Individual") && relation.matches("member"))
            return true;
        return false;
    }
}

public class Network {
    HashMap<Integer, Node> Nodes = new HashMap<Integer, Node>();

    public boolean createNode(Scanner obj) {
        System.out.println("Enter Node Type");
        String typeName = obj.nextLine();
        if (typeName.equalsIgnoreCase("Individual")) {
            Node temp = new Individual(obj);
            Nodes.put(temp.getID(), temp);
            return true;
        } else if (typeName.equalsIgnoreCase("Group")) {
            Node temp = new Group(obj);
            Nodes.put(temp.getID(), temp);
            return true;
        } else if (typeName.equalsIgnoreCase("Organisation")) {
            Node temp = new Organisation(obj);
            Nodes.put(temp.getID(), temp);
            return true;
        } else if (typeName.equalsIgnoreCase("Business")) {
            Node temp = new Business(obj);
            Nodes.put(temp.getID(), temp);
            return true;
        }
        return false;
    }

    public void deleteNode(Scanner obj) {
        System.out.println("Enter Node ID");
        int key = Integer.parseInt(obj.nextLine());
        Node currNode = Nodes.get(key);
        currNode.link.forEach((n, r) -> {
            n.link.remove(currNode);
        });
        Nodes.remove(key);
        System.out.println("Node Deleted");
    }

    public void searchNode(Scanner obj) {
        System.out.println("Enter Keytype");
        String keyType = obj.nextLine();
        System.out.println("Enter Key");
        String key = obj.nextLine();

        ArrayList<Integer> ans = new ArrayList<Integer>();

        if (keyType.equalsIgnoreCase("name")) {
            Nodes.forEach((id, n) -> {
                if (n.getName().toLowerCase().contains(key.toLowerCase())) {
                    ans.add(id);
                }
            });
        } else if (keyType.equalsIgnoreCase("type")) {
            Nodes.forEach((id, n) -> {
                if (n.getClass().getName().equalsIgnoreCase(key)) {
                    ans.add(id);
                }
            });
        } else if (keyType.equalsIgnoreCase("birthday")) {
            Nodes.forEach((id, n) -> {
                if (n.getClass().getName().equalsIgnoreCase("Individual")) {
                    Individual n_ = (Individual) n;
                    if (n_.getBirthDate().equals(LocalDate.parse(key))) {
                        ans.add(id);
                    }
                }
            });
        }
        if (ans.size() == 0) {
            System.out.println("No such node found");
            return;
        }
        for (int i : ans) {
            System.out.println("*******\n" + Nodes.get(i));
        }

    }

    public void printLinkedNodes(Scanner obj) {
        System.out.println("Enter Node ID");
        int x = Integer.parseInt(obj.nextLine());

        System.out.println("Links:");
        Nodes.get(x).link.forEach((n, v) -> {
            System.out.println(Nodes.get(x).getName() + "--" + v + "--" + n.getName() + ", ID: " + n.getID());
        });
    }

    public void createContent(Scanner obj) {
        System.out.println("Enter Node ID");
        int x = Integer.parseInt(obj.nextLine());
        System.out.println("Enter Content for new Post");
        String content = obj.nextLine();
        Nodes.get(x).postContent(content, 0);
    }

    public void repostContent(Scanner obj) {

        System.out.println("Enter Node ID");
        int x = Integer.parseInt(obj.nextLine());
        Node currNode = Nodes.get(x);
        System.out.println("Select Post No. to repost");
        ArrayList<String> originalPosts = (ArrayList<String>) currNode.contents;
        int i = 0;
        for (String post : originalPosts) {
            i++;
            System.out.println(i + ": " + post);
        }
        int select = Integer.parseInt(obj.nextLine());
        currNode.postContent(originalPosts.get(select - 1), 1);

    }

    public boolean createLinkForNodes(Scanner obj) {
        System.out.println("Enter Node 1 ID");
        int x = Integer.parseInt(obj.nextLine());
        System.out.println("Enter Node 2 ID");
        int y = Integer.parseInt(obj.nextLine());
        System.out.println("Enter Relation");
        String relation = obj.nextLine();

        boolean returnTrue = Nodes.get(x).insertLink(Nodes.get(y), relation)
                && Nodes.get(y).insertLink(Nodes.get(x), relation);
        return returnTrue;
    }

    public void searchContent(Scanner obj) {

        ArrayList<String> retrieve = new ArrayList<String>();
        System.out.print("Enter Node ID");
        int x = Integer.parseInt(obj.nextLine());
        System.out.println("Enter Search String");
        String searchKey = obj.nextLine();
        for (String content : Nodes.get(x).originalContents) {
            if (content.contains(searchKey)) {
                retrieve.add(content);
            }
        }
        if (retrieve.size() > 0) {
            System.out.println("Searched Content");
            for (String r : retrieve)
                System.out.println(r);
        } else
            System.out.println("No Post found");

    }

    public void DisplayLinkedContent(Scanner obj) {
        System.out.println("Enter Node ID");
        int x = Integer.parseInt(obj.nextLine());
        Nodes.get(x).link.forEach((k, v) -> {
            System.out.println("Linked Node ID:" + k.getID());
            for (String post : k.contents) {
                System.out.println(post);
            }
        });

    }

    public void DisplayNodes() {
        Nodes.forEach((id, n) -> {
            System.out.println("*******\n" + n);
        });
    }

    public static void main(String[] args) {
        Network network = new Network();
        Scanner obj = new Scanner(System.in);
        int flag = -1;
        while (flag != 0) {
            System.out.println("\nEnter 1 for Creating Node");
            System.out.println("Enter 2 for Deleting Node");
            System.out.println("Enter 3 for creating a link between two nodes");
            System.out.println("Enter 4 for Searching for Node");
            System.out.println("Enter 5 for Printing Linked Nodes to a Node");
            System.out.println("Enter 6 for Creating an original Post");
            System.out.println("Enter 7 for Reposting an old Post");
            System.out.println("Enter 8 for Searching a content posted by a Node");
            System.out.println("Enter 9 to Display all content posted by nodes linked to a given node");
            System.out.println("Enter 10 to Display all nodes");
            System.out.println("Enter 0 to exit");
            flag = Integer.parseInt(obj.nextLine());
            boolean check;
            switch (flag) {
                case 0:
                    break;
                case 1:
                    check = network.createNode(obj);
                    if (check == false) {
                        System.out.println("Invalid Type name,Node not created");
                    } else
                        System.out.println("Node Created");
                    break;
                case 2:
                    network.deleteNode(obj);
                    break;
                case 3:
                    check = network.createLinkForNodes(obj);
                    if (check == false) {
                        System.out.println("Invalid relation,Link not created");
                    } else
                        System.out.println("Link created");
                    break;
                case 4:
                    network.searchNode(obj);
                    break;
                case 5:
                    network.printLinkedNodes(obj);
                    break;
                case 6:
                    network.createContent(obj);
                    break;
                case 7:
                    network.repostContent(obj);
                    break;
                case 8:
                    network.searchContent(obj);
                    break;
                case 9:
                    network.DisplayLinkedContent(obj);
                    break;
                case 10:
                    network.DisplayNodes();
                    break;
                default:
                    System.out.println("Enter Valid Option");
            }

        }
        obj.close();
    }
}