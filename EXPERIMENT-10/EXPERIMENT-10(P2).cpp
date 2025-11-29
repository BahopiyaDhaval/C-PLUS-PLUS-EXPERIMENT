#include <iostream>
#include <string>
using namespace std;

// Authority levels (higher value = higher priority)
enum Authority { JUNIOR = 1, MID = 2, SENIOR = 3 };

// Document representation
struct Document {
    int id;
    string title;
    Authority level;
    Document(int i=0, string t="", Authority l=JUNIOR) : id(i), title(t), level(l) {}
};

// Node for linked-list priority queue
struct Node {
    Document doc;
    int priority; // numeric priority derived from Authority
    Node* next;
    Node(const Document &d) : doc(d), priority(static_cast<int>(d.level)), next(nullptr) {}
};

// Priority queue using single-linked list (highest priority at head).
// For equal priorities we preserve FIFO: new nodes of same priority are appended after existing ones.
class PriorityQueueLL {
    Node* head;
public:
    PriorityQueueLL(): head(nullptr) {}
    ~PriorityQueueLL() {
        while (head) { Node* t = head->next; delete head; head = t; }
    }

    bool isEmpty() const { return head == nullptr; }

    // Enqueue document by priority (higher priority value goes earlier)
    void enqueue(const Document &doc) {
        Node* n = new Node(doc);
        if (!head || n->priority > head->priority) {
            // insert at front
            n->next = head;
            head = n;
            return;
        }
        // find insertion point: after all nodes with priority >= n->priority
        Node* cur = head;
        while (cur->next && cur->next->priority >= n->priority) {
            cur = cur->next;
        }
        // insert after cur -> this preserves FIFO among same-priority docs
        n->next = cur->next;
        cur->next = n;
    }

    // Process next document (dequeue highest-priority). Returns false if queue empty.
    bool processNext() {
        if (!head) {
            cout << "No documents to process.\n";
            return false;
        }
        Node* t = head;
        head = head->next;
        cout << "Processing Document ID: " << t->doc.id
             << ", Title: \"" << t->doc.title << "\""
             << ", Level: " << (t->doc.level==SENIOR? "SENIOR" : t->doc.level==MID? "MID" : "JUNIOR")
             << '\n';
        delete t;
        return true;
    }

    // Display queue (head -> tail)
    void display() const {
        if (!head) { cout << "(empty)\n"; return; }
        cout << "Queue [ID:Title:Level] -> ";
        Node* cur = head;
        while (cur) {
            cout << "[" << cur->doc.id << ":" << cur->doc.title << ":" 
                 << (cur->doc.level==SENIOR? "S" : cur->doc.level==MID? "M" : "J") << "] ";
            cur = cur->next;
        }
        cout << '\n';
    }
};

// Demo
int main() {
    PriorityQueueLL q;

    // Simulate arrival of documents (id, title, authority)
    q.enqueue(Document(101, "Budget Proposal", MID));
    q.enqueue(Document(102, "Team Leave Request", JUNIOR));
    q.enqueue(Document(103, "Executive Summary", SENIOR));
    q.enqueue(Document(104, "Project Plan", MID));
    q.enqueue(Document(105, "Security Patch Approval", SENIOR));
    q.enqueue(Document(106, "Desk Move", JUNIOR));

    cout << "Initial queue state:\n";
    q.display();
    cout << "\nProcessing documents in priority order:\n";

    // Process until empty
    while (q.processNext()) {
        cout << "Queue now: ";
        q.display();
    }

    return 0;
}

