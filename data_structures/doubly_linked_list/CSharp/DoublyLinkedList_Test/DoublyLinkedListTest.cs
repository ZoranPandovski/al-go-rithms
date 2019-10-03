using System.Collections.Generic;
using Xunit;

using DoublyLinkedList;

namespace DoublyLinkedList_Test
{
    public class DoublyLinkedListTest
    {
        [Fact]
        public void AddHead_Node_Should_Become_Head()
        {
            // Arrange
            int[] myNums = { 1, 2, 3, 4, 5 };
            var myLinkedList = new DoublyLinkedList<int>(myNums);

            // Act
            myLinkedList.AddHead(45);

            // Assert
            Assert.Equal(45, myLinkedList.Head);
        }

        [Fact]
        public void AddTail_Node_Should_Become_Tail()
        {
            // Arrange
            int[] myNums = { 1, 2, 3, 4, 5 };
            var myLinkedList = new DoublyLinkedList<int>(myNums);

            // Act
            myLinkedList.AddTail(7777);

            // Assert
            Assert.Equal(7777, myLinkedList.Tail);
        }

        [Fact]
        public void RemoveHead_Next_Node_Should_Be_Head()
        {
            // Arrange
            int[] myNums = { 1, 2, 3, 4, 5 };
            var myLinkedList = new DoublyLinkedList<int>(myNums);

            // Act
            myLinkedList.RemoveHead();

            // Assert
            Assert.Equal(2, myLinkedList.Head);
        }

        [Fact]
        public void RemoveTail_Next_Node_Should_Be_Tail()
        {
            // Arrange
            int[] myNums = { 1, 2, 3, 4, 5 };
            
            var myLinkedList = new DoublyLinkedList<int>(myNums);

            // Act
            myLinkedList.RemoveTail();

            // Assert
            Assert.Equal(4, myLinkedList.Tail);
        }

        [Fact]
        public void Find_5_Should_Return_True()
        {
            // Arrange
            int[] myNums = { 1, 2, 3, 4, 5 };

            var myLinkedList = new DoublyLinkedList<int>(myNums);

            // Act
            var isFound = myLinkedList.Find(5);

            // Assert
            Assert.True(isFound);
        }

        [Fact]
        public void IsEmpty_Should_Return_False_Count_Equal_5()
        {
            // Arrange
            int[] myNums = { 1, 2, 3, 4, 5 };

            var myLinkedList = new DoublyLinkedList<int>(myNums);

            // Act
            var isEmpty = myLinkedList.IsEmpty;

            // Assert
            Assert.False(isEmpty);
        }

        [Fact]
        public void IsEmpty_Should_Return_True_Count_Equal_0()
        {
            // Arrange
            int[] myNums = { };

            var myLinkedList = new DoublyLinkedList<int>(myNums);

            // Act
            var isEmpty = myLinkedList.IsEmpty;

            // Assert
            Assert.True(isEmpty);
        }

        [Fact]
        public void GetIndex_4_Should_Equal_5()
        {
            // Arrange
            int[] myNums = { 1, 2, 3, 4, 5 };

            var myLinkedList = new DoublyLinkedList<int>(myNums);

            // Act
            var index = myLinkedList.GetIndex(4);

            // Assert
            Assert.Equal(5, index);
        }

        [Fact]
        public void SetIndex_2_10_Should_Set_Index_2_To_10()
        {
            // Arrange
            int[] myNums = { 1, 2, 3, 4, 5 };

            var myDoublyLinkedList = new DoublyLinkedList<int>(myNums);

            // Act
            myDoublyLinkedList.SetIndex(2, 10);

            // Assert
            Assert.Equal(10, myDoublyLinkedList[2]);
        }

        [Fact]
        public void RemoveAll_Should_Delete_All_5s()
        {
            // Arrange
            int[] myNums = { 5, 5, 5, 3, 2, 5 };

            var myDoublyLinkedList = new DoublyLinkedList<int>(myNums);

            // Act
            myDoublyLinkedList.RemoveAll(5);

            // Assert
            Assert.False(myDoublyLinkedList.Find(5));
        }

        [Fact]
        public void Remove_1_Should_Return_True()
        {
            // Arrange
            int[] myNums = { 5, 5, 5, 3, 2, 5 };

            var myDoublyLinkedList = new DoublyLinkedList<int>(myNums);

            // Act
            bool isRemoved = myDoublyLinkedList.Remove(1);

            // Assert
            Assert.True(isRemoved);
        }

        [Fact]
        public void Remove_2_Should_Return_False()
        {
            // Arrange
            int[] myNums = { 1 };

            var myDoublyLinkedList = new DoublyLinkedList<int>(myNums);

            // Act
            bool isRemoved = myDoublyLinkedList.Remove(2);

            // Assert
            Assert.False(isRemoved);
        }

        [Fact]
        public void AddHead_Should_Increment_Count()
        {
            // Arrange
            int[] myNums = { 1 };

            var myDoublyLinkedList = new DoublyLinkedList<int>(myNums);

            var theCount = myDoublyLinkedList.Count;
            
            // Act
            myDoublyLinkedList.AddHead(7);
            myDoublyLinkedList.AddHead(7);
            myDoublyLinkedList.AddHead(7);
            myDoublyLinkedList.AddHead(7);
            myDoublyLinkedList.AddHead(7);

            // Assert
            Assert.Equal(theCount + 5, myDoublyLinkedList.Count);
        }

        [Fact]
        public void RemoveTail_Should_Decrement_Count()
        {
            // Arrange
            int[] myNums = { 1 };

            var myDoublyLinkedList = new DoublyLinkedList<int>(myNums);

            var theCount = myDoublyLinkedList.Count;

            // Act
            myDoublyLinkedList.RemoveTail();

            // Assert
            Assert.Equal(theCount - 1, myDoublyLinkedList.Count);
        }
    }
}