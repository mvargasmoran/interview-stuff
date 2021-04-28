/*
 * This problem was asked by Google.
 * Determine whether a doubly linked list is a palindrome.
 * What if it's singly linked?
 *
 * For example, 1 -> 4 -> 3 -> 4 -> 1
 *  returns True
 * while 1 -> 4
 *  returns False.
 */

class Node {
  constructor(data) {
    this.data = data;
    this.prev = null;
    this.next = null;
  }
}

class DoublyLinkedList {
  constructor() {
    this.head = null;
    this.tail = null;
    this.length = null;
  }

  push(data) {
    this.length++;
    const newNode = new Node(data);

    if(!this.head) {
      this.head = newNode;
      this.tail = newNode;
    } else {
      newNode.prev = this.tail;
      this.tail.next = newNode;
      this.tail = newNode;
    }
  }

// The exercise doesn't need a pop method
//  pop() {
//    (!this.head) && return null;
//
//    const returningTail = this.tail;
//
//    const tailPrevNode = this.tail.prev;
//    if (tailPrevNode) {
//      tailPrevNode.next = null;
//      this.tail = tailPrevNode;
//    } else {
//      this.head = null;
//      this.tail = null;
//    }
//
//    this.length--;
//    return returningTail;
//  }

  // implement later, is not relevant to this exercise
  //insertAfter(data, prevNode) {
  //}
}

const createNewDLL = (dataArray) => {
  const newDLL = new DoublyLinkedList();

  dataArray.forEach(data => {
    newDLL.push(data);
  });

  return newDLL;
}

const palindromeDet = (dataArray) => {
  const dll = createNewDLL(dataArray);
  let current = dll.head;
  let compareString = '';

  do {
    compareString += current.data;
    current = current.next;
  } while (current);

  const reversedString = compareString.split('').reverse().join('');
//console.log({compareString, reversedString});

  return compareString === reversedString;
};

module.exports = palindromeDet;
