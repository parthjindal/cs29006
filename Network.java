import java.util.*;
import java.time.*;
import java.awt.geom.*;

abstract class Node {
    protected int id;
    protected String name;
    protected Date createTime;
    static int count = 0;
    public Set<String> contents;
    public Map<Node, String> link;

    Node() {
        contents = new HashSet<String>();
        link = new HashMap<Node, String>();
        createTime = new Date();
        id = count;
        count++;
    }

    abstract public void setInfo(Scanner obj);
    abstract public void printNode();
    abstract public boolean checkLinkSanity(Node x, String relation);

    @Override
    public String toString() {
        return String.format("%d", id);
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

    public void insertLink(Node x, String relation) {
        if (checkLinkSanity(x, relation) == false)
            return;
        else
            link.put(x, relation);
        return;
    }

    public void postContent(String content) {
        if (contents.contains(content) == false) {
            contents.add(content);
        }
        System.out.println(content);
    }

    public ArrayList<String> searchContent(String content) {
        ArrayList<String> retrieve = new ArrayList<String>();
        for(String x:contents){
            if(x.contains(content)){
                retrieve.add(x);
            }
        }
        return retrieve;
    }

};

class Individual extends Node {
    private LocalDate birthDate;

    Individual() {
        super();
    }

    public LocalDate getBirthDate() {
        return this.birthDate;
    }

    public void setBirthdate(Scanner obj) {
        System.out.print("Enter DOB(yyyy-mm-dd)");
        String dateString = obj.nextLine();
        birthDate = LocalDate.parse(dateString);

    }

    public void setInfo(Scanner obj) {
        setName(obj);
        setBirthdate(obj);
    }

    public boolean checkLinkSanity(Node x, String relation) {
        if (x.getClass().getName().matches("Group|Organisation") && relation.matches("member")) {
            return true;
        } else if (x.getClass().getName().matches("Business") && relation.matches("member|owner")) {
            return true;
        }
        return false;
    }

    public void printNode() {
        System.out.println("Name: " + this.name);
        System.out.println("Type: " + this.getClass().getName());
        System.out.println("Date Of Birth: " + this.birthDate);
        System.out.println("Posts:");
        for (String content : this.contents) {
            System.out.println(content);
        }
        System.out.println("Links:");
        for (Map.Entry<Node, String> x : link.entrySet()) {
            System.out.println(x.getValue() + "-->" + x.getKey().getName());
        }
    }
};

class Group extends Node {

    Group() {
        super();
    }

    public void setInfo(Scanner obj) {
        setName(obj);
    }

    public boolean checkLinkSanity(Node x, String relation) {
        if (x.getClass().getName().matches("Individual") && relation.matches("member"))
            return true;
        return false;
    }

    public void printNode() {
        System.out.println("Name: " + name);
        System.out.println("Type: " + this.getClass().getName());
        System.out.println("Posts:");
        for (String content : contents) {
            System.out.println(content);
        }
        System.out.println("Links:");
        for (Map.Entry<Node, String> x : link.entrySet()) {
            System.out.println(x.getValue() + "-->" + x.getKey().name);
        }
    }
}

class Business extends Group {
    protected Point2D.Double location;

    Business() {
        super();
        location = new Point2D.Double();
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
    public void setInfo(Scanner obj) {
        setName(obj);
        setLocation(obj);

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
    public void printNode() {
        System.out.println("Name: " + this.name);
        System.out.println("Type: " + this.getClass().getName());
        System.out.println("Location: " + this.location.getX() + "," + this.location.getY());
        System.out.println("Posts:");
        for (String content : contents) {
            System.out.println(content);
        }
        System.out.println("Links:");
        for (Map.Entry<Node, String> x : link.entrySet()) {
            System.out.println(x.getValue() + "-->" + x.getKey().name);
        }
    }
};

class Organisation extends Business {
    Organisation() {
        super();
    }

    @Override
    public boolean checkLinkSanity(Node x, String relation) {
        if (x.getClass().getName().matches("Individual") && relation.matches("member"))
            return true;
        return false;
    }
}

public class Network {
    ArrayList<Node> Nodes = new ArrayList<Node>();

    public void createNode(Scanner obj) {
        System.out.println("Enter Node Type");
        String typeName = obj.nextLine();
        if (typeName.equalsIgnoreCase("Individual")) {
            Node temp = new Individual();
            temp.setInfo(obj);
            Nodes.add(temp);
        } else if (typeName.equalsIgnoreCase("Group")) {
            Node temp = new Group();
            temp.setInfo(obj);
            Nodes.add(temp);
        } else if (typeName.equalsIgnoreCase("Organisation")) {
            Node temp = new Organisation();
            temp.setInfo(obj);
            Nodes.add(temp);
        } else if (typeName.equalsIgnoreCase("Business")) {
            Node temp = new Business();
            temp.setInfo(obj);
            Nodes.add(temp);
        }
    }

    public void deleteNode(Integer id) {
        Iterator<Node> iter = Nodes.iterator();
        while (iter.hasNext()) {
            Node x = (Node) iter.next();
            if (x.getID() == id) {
                for (Map.Entry<Node, String> y : x.link.entrySet()) {
                    y.getKey().link.remove(x);
                }
                iter.remove();
                break;
            }
        }
    }

    public int searchNode(String key, String keyType) {
        int ans = -1;
        if (keyType.equalsIgnoreCase("name")) {

            for (int i = 0; i < Nodes.size(); i++) {
                if (Nodes.get(i).getName().equalsIgnoreCase(key)) {
                    ans = i;
                    break;
                }
            }
        } else if (keyType.equalsIgnoreCase("type")) {
            for (int i = 0; i < Nodes.size(); i++) {
                if (Nodes.get(i).getClass().getName().equalsIgnoreCase(key)) {
                    ans = i;
                    break;
                }
            }
        } else if (keyType.equalsIgnoreCase("birthday")) {
            for (int i = 0; i < Nodes.size(); i++) {
                Individual x = (Individual)Nodes.get(i);
                if (x.getBirthDate().equals(LocalDate.parse(key))){
                    ans = i;
                    break;
                }
            }
        }
        
        return ans;
    }

    public static void main(String[] args) {

    }
}
