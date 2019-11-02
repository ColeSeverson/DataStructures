using System;
using System.Collections.Generic;

namespace Libraries
{
    public class Node<T>
    {
        public Node<T> Left{ get; set; }
        public Node<T> Right{ get; set; }
        public Node<T> Next{ get { return Left; } set { Left = value; } }
        public T Data{ get; set; }
        public Node(T data, Node<T> left=null, Node<T> right=null) {
            this.Data = data;
            this.Left = left;
            this.Right = right;
        }
    }
    public class LinkedList<T>
    {
        public Node<T> Head{ get; set; }
        public int Length { get; private set; }

        //Constructors
        public LinkedList() {
            Head = null;
            Length = 0;
        }
        public LinkedList(T data) {
            Head = new Node<T>(data);
            Length = 1;
        }

        //Insertion Methods
        public Node<T> Insert(Node<T> node) {
            var current = Head;
            while(current.Next != null) {
                current = current.Next;
            }
            current.Next = node;
            Length += 1;
            return Head;
        }
        public Node<T> Insert(T data) {
            Node<T> node = new Node<T>(data);
            return Insert(node);
        }
        public Node<T> Insert(List<Node<T>> list) {
            foreach(var node in list) {
                Insert(node);
            }
            return Head;
        }
        public Node<T> Insert(List<T> list) {
            foreach(var data in list) {
                Insert(data);
            }
            return Head;
        }

        //Deletion Methods
        public Node<T> Delete(Node<T> node) {
            var current = Head;
            var parent = Head;
            while(current != null) {
                if (current.Equals(node)) {
                    if(current.Equals(Head)) {
                        Head = current.Next;
                    } else {
                        parent.Next = current.Next;
                    }
                    Length -= 1;
                    return Head;
                }
                parent = current;
                current = current.Next;
            }
            Length -= 1;
            return Head;
        }
        public Node<T> Delete(T data) {
            var current = Head;
            var parent = Head;
            while(current != null) {
                if (current.Data.Equals(data)) {
                    if(current.Equals(Head)) {
                        Head = current.Next;
                    } else {
                        parent.Next = current.Next;
                    }
                    Length -= 1;
                    return Head;
                }
                parent = current;
                current = current.Next;
            }
            Length -= 1;
            return Head;
        }

        //Accessor Methods
        public Node<T> this[int i] {
            get {
                if(i + 1 > Length)
                    throw new System.IndexOutOfRangeException("Indice out of range");

                var current = Head;
                for(; i > 0; i--) {
                    current = current.Next;
                }
                return current;
            }
        }

        //Misc Methods
        
    }
}
