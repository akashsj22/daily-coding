class Node {
    constructor(data) {
        this.data = data;
        this.next = null;
    }
}

function count(head, key) {
    if (head === null) {
        return 0;
    }
    
    let ans = count(head.next, key);
    
    if (head.data === key) {
        ans++;
    }
    
    return ans;
}

let head = new Node(1);
head.next = new Node(2);
head.next.next = new Node(1);
head.next.next.next = new Node(2);
head.next.next.next.next = new Node(1);

let key = 1;

console.log(count(head, key));
