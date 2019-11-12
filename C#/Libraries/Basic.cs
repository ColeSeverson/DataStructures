using System;
using System.Collections.Generic;

namespace DataStructures {

    public class LinkedList<T>
    {
        private Node<T> Head;
        public int Length { get; private set; }

        //Constructors
        public LinkedList() {
            Head = null;
            Length = 0;
        }

        //Insertion Methods
        public void Insert(Node<T> node) {
            Length += 1;
            if(Head == null) {
                Head = node;
                return;
            }
            var current = Head;
            while(current.Next != null) {
                current = current.Next;
            }
            current.Next = node;
        }
        public void Insert(T data) {
            Node<T> node = new Node<T>(data);
            Insert(node);
        }
        public void Insert(List<Node<T>> list) {
            foreach(var node in list) {
                Insert(node);
            }
        }
        public void Insert(List<T> list) {
            foreach(var data in list) {
                Insert(data);
            }
        }
        public void InsertAt(Node<T> node, int index) {
            var current = Head;
            for(; index > 0 && current.Next != null; index--) {
                current = current.Next;
            }
            var temp = current.Next;
            current.Next = node;
            node.Next = temp;
            return;
        }

        //Deletion Methods
        public void Delete(Node<T> node) {
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
                    return;
                }
                parent = current;
                current = current.Next;
            }
            Length -= 1;
            return;
        }
        public void Delete(T data) {
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
                    return;
                }
                parent = current;
                current = current.Next;
            }
            Length -= 1;
            return;
        }

        //Accessor Methods
        public T this[int i] {
            get {
                return At(i);
            }
        }
        public T At(int i) {
            if(i + 1 > Length)
                throw new System.IndexOutOfRangeException("Indice out of range");

            var current = Head;
            for(; i > 0; i--) {
                current = current.Next;
            }
            return current.Data;
        }

        //Misc Methods
        public void Reverse() {
            Node<T> parent = null;
            Node<T> current = Head;
            Node<T> next = null;

            while(current != null) {
                next = current.Next;
                current.Next = parent;
                parent = current;
                current = next;
            }
            Head = parent;
        }
        public override string ToString(){
            string buffer = "";
            var current = Head;
            while(current != null) {
                buffer = buffer + " " + current.Data;
                current = current.Next;
            }
            return buffer;
        }
    }

    public class BinaryTree<T> {
        private Node<T> Root;
        public int Depth { get; private set; }
        public int Count { get; private set; }

        //Constructors
        //Less than 0 is less, more is greater
        public delegate int Compare(T a, T b);
        public Compare Comp { get; private set; }
        public BinaryTree(Compare compare_method) {
            Comp = compare_method;
        }
        public void Insert(Node<T> node) {
            if (Root == null) {
                Root = node;
                return;
            }
            var current = Root;
            while(current != null) {
                if(Comp(node.Data, current.Data) < 0) {
                    //Left
                    if(current.Left != null) {
                        current = current.Left;
                        continue;
                    } else {
                        current.Left = node;
                        return;
                    }
                } else {
                    //Right
                    if(current.Right != null) {
                        current = current.Right;
                        continue;
                    } else {
                        current.Right = node;
                        return;
                    }
                }
            }
        }
        public void Insert(T data) {
            var node = new Node<T>(data);
            Insert(node);
        }
        //Delete Methods
        private Node<T> DeleteRec(Node<T> current, T data) {
            if(current == null) 
                return current;
            
            if(Comp(data, current.Data) < 0) {
                current.Left = DeleteRec(current.Left, data);
            }
            else if(Comp(data, current.Data) > 0) {
                current.Right = DeleteRec(current.Right, data);
            } else {
                //We found him boys
                if(current.Left == null) {
                    return current.Right;
                } else if (current.Right == null) {
                    return current.Left;
                } else {
                    current.Data = FindMin(current.Right).Data;
                    current.Right = DeleteRec(current.Right, current.Data);
                }
            }
            return current;
        }
        public void Delete(T data) {
            Root = DeleteRec(Root, data);
        }
        //Accessor Methods

        //Misc Methods
        private Node<T> FindMin(Node<T> current) {
            if(current == null)
                return null;

            while(current.Left != null) {
                current = current.Left;
            }
            return current;
        }
        public void Print() {
            PrintTree(Root);
        }
        private void PrintTree(Node<T> current, int depth=0) {
            if (current == null) {
                return;
            }
            PrintTree(current.Left, depth + 1);

            Console.WriteLine(new String(' ', depth) + current.Data);

            PrintTree(current.Right, depth + 1);
        }
    }
}
