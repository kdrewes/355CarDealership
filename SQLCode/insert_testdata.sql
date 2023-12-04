INSERT INTO Employee (Employee_ID, Name, Make_Responsible, Phone_Number, Email, Address) VALUES
(1, 'John Doe', 'Honda', '555-0100', 'john.doe@email.com', '1234 Main St'),
(2, 'Jane Smith', 'Toyota', '555-0101', 'jane.smith@email.com', '1235 Main St'),
(3, 'Emily Johnson', 'Ford', '555-0102', 'emily.johnson@email.com', '1236 Main St');

INSERT INTO Customer (Customer_ID, Name, Phone_Number, Email, Address) VALUES
(101, 'Alice Brown', '555-0200', 'alice.brown@email.com', '5678 Park Ave'),
(102, 'Bob Green', '555-0201', 'bob.green@email.com', '5679 Park Ave'),
(103, 'Charlie Black', '555-0202', 'charlie.black@email.com', '5680 Park Ave');

INSERT INTO Vehicle (VIN, Manufacturer, Model_Name, Model_Year, Price) VALUES
('1HGBH41JXMN109186', 'Honda', 'Civic', '2021-01-01', 20000.00),
('JH4KA7660MC000000', 'Toyota', 'Corolla', '2022-01-01', 18000.00),
('2HGES267XNH590480', 'Ford', 'Focus', '2023-01-01', 22000.00);

INSERT INTO Sale (Sale_ID, Emp_ID, Cust_ID, VIN, Price, Sale_Date) VALUES
(1001, 1, 101, '1HGBH41JXMN109186', 20000.00, '2023-03-01'),
(1002, 2, 102, 'JH4KA7660MC000000', 18000.00, '2023-03-02'),
(1003, 3, 103, '2HGES267XNH590480', 22000.00, '2023-03-03');
