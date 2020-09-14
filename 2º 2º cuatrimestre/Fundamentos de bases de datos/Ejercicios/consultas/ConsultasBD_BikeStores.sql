/* 1. Seleccionar productos con precio superior a 1000 */
SELECT * FROM Products
	WHERE list_price > 1000;

/* 2. Seleccionar nombres y correos electrónicos de tiendas de Santa Cruz */
SELECT store_name, email FROM Stores
	WHERE city = 'Santa Cruz';

/* 3. Seleccionar precio+descuento de todos los items vendidos */
SELECT list_price, discount, FROM Order_Items;

/* 4. Seleccionar el email del personal cuyo nombre y apellidos es Fabiola Jackson */
SELECT email FROM Staffs
	WHERE first_name = 'Fabiola'
	AND   last_name  = 'Jackson';

/* 5. Seleccionar el personal que no tenga manager. Es obligatorio hacer uso de la condición IS NULL en la consulta */
SELECT * FROM Staffs
	WHERE manager_id IS NULL;

/* 6. Seleccionar nombre y apellidos de personal (staffs) que hayan procesado pedidos de clientes de la ciudad de New York */
SELECT staffs.first_name, staffs.last_name FROM Staffs, Customers, Orders
	WHERE Staffs.staff_id       = Orders.staff_id
	AND   Customers.customer_id = Orders.customer_id
	AND   city                  = 'New York';

/* 7. Seleccionar nombres de tiendas que tienen productos de la categoría Mountain Bikes */
SELECT store_name FROM Stores, Stocks, Products, Category
	WHERE Stores.store_id          = Stocks.store_id
	AND   Products.product_it      = Stocks.product_id
	AND   Categories.category_name = 'Mountain Bikes'
	AND   Categories.category_id   = Products.category_id;

/* 8. Seleccionar nombres de productos vendidos, y cantidad, a clientes que viven en Bronx */
SELECT DISTINCT Produtcs.product_name, Order_Items.quantity FROM Products, Order_Items, Orders, Customers
	WHERE Orders.customer_id=Customers.customer_id
	AND   Customers.city = 'Bronx';

/* 9. Seleccionar nombre y apellidos de clientes que han comprado productos de la categoría Mountain Bikes */
SELECT DISTINCT first_name, last_name FROM Customers, Products, Categories, Orders, Order_Items
	WHERE Orders.customer_id       = Customers.customer_id
	AND   Order_Items.product_id   = Products.product_id
	AND   Products.category_id     = Categories.category_id
	AND   Categories.category_name = 'Mountain Bikes';

/* 10. Seleccionar las marcas que ha vendido el personal de la tienda localizada en Santa Cruz */
SELECT DISTINCT brand_name FROM Stores, Order_Items, Products, Brands
	WHERE STORES.city          = 'Santa Cruz'
	AND Order_Items.product_id = Products.product_id
	AND Products.brand_id      = Brands.brand_id;

/* 11. Seleccionar Descuento mínimo, máximo y promedio que se hace de los items vendidos */
SELECT MIN(discount), MAX(discount), AVG(discount) FROM Order_Items;

/* 12. Seleccionar Descuento mínimo, máximo y promedio que se hace de los items vendidos a personas de New York */
SELECT MIN(discount), MAX(discount), AVG(discount) FROM Order_Items, Orders, Customers
	WHERE Order_Items.order_id = Orders.order_id
	AND   Orders.customer_id   = Customers.customer_id
	AND   Customers.city       = 'New York';

/* 13. Seleccionar marcas que tengan algún producto que no esté en stock */
SELECT DISTINCT brand_name FROM Products, Brands
	WHERE Products.brand_id = Brands.brand_id
	AND   NOT EXISTS (
		SELECT * FROM Stocks
			WHERE Stocks.product_id = products.product_id
	);

/* 14. Seleccionar categorías que no tengan productos que no estén en stock (PISTA: Usar 3 consultas anidadas haciendo uso de NOT EXISTS) */
SELECT * FROM Categories
	WHERE NOT EXISTS (
		SELECT * FROM Products p
			WHERE NOT EXISTS (
				SELECT * FROM Stocks
					WHERE product_id = p.product_id
			)
	);

/* 15. Seleccionar nombres de productos que no hayan sido vendidos */
SELECT product_name FROM Products p
	WHERE NOT EXISTS (
		SELECT * FROM Order_Items
			WHERE product_id = p.product_id
	);

/* 16. Seleccionar nombre de clientes que hayan comprado la máxima cantidad de algún producto, junto con el nombre del producto */
SELECT DISTINCT first_name, Products.product_name FROM Customers, Products, Order_Items, Orders
	WHERE Order_Items.order_id = Orders.order_id
	AND   Orders.customer_id   = Customers.customer_id
	AND   EXISTS (
		SELECT MAX(quantity) FROM Products, Order_Items
			WHERE Order_Items.product_id = Products.product_id
	);

/* 17. Seleccionar nombre y apellidos de personal que no haya vendido nada en 2016 (es decir, que no haya procesado pedidos en ese año) */
SELECT first_name, last_name FROM Staffs, Orders
	WHERE NOT EXISTS (
		SELECT * FROM Staffs, Orders WHERE
			Staffs.staff_id = Orders.staff_id
	);

/* 18. Seleccionar nombres de tiendas y clientes que sean de la misma ciudad */
SELECT store_name, first_name, last_name FROM Stores, Customers
	WHERE Customers.city = Stores.city;

/* 19. Seleccionar nombres de tiendas y clientes que sean de la misma ciudad, y donde los clientes hayan hecho pedidos a otras tiendas que no sean esas */
SELECT store_name, first_name, last_name FROM Stores t, Customers c
	WHERE Customers.city = Stores.city
	AND   NOT EXISTS (
		SELECT * FROM Orders
			WHERE Orders.customer_id  = c.customer_id
			AND   Orders.store_id    != t.store_id
	);

/* 20. Seleccionar nombres de clientes y su ciudad que hayan comprado los productos más caros. */
SELECT DISTINCT first_name, last_name, city FROM Customers, Orders, Order_Items
	WHERE EXISTS (
		SELECT MAX(list_price) FROM Products
			WHERE Order_Items.product_id = Products.product_id
	);

/* 21. Seleccionar nombre de tiendas que tengan en stock productos de al menos dos marcas distintas */
SELECT store_name FROM Stores

/* 22. Seleccionar nombre y teléfono de clientes que sean de New York o de Bronx */
(SELECT first_name, phone FROM Customers
	WHERE Customers.city='New York'
)
UNION
(SELECT first_name, phone FROM Customers
	Where Customers.city='Bronx'
);

/* 23. Encontrar el producto de precio máximo USANDO OPERADORES CONJUNTISTAS (sin usar operadores adicionales como min,max,all, etc.)  */
(SELECT product_name FROM Products p1)
	MINUS
(SELECT product_name FROM Products p2
	WHERE p1.list_price < p2.list_price
);

/* 24. Encontrar los nombres de productos que no estén en stock USANDO OPERADORES CONJUNTISTAS  */
SELECT product_name FROM Products
	WHERE Products.product_name IN (
		(SELECT p2.product_id FROM products p2)
			MINUS
		(SELECT product_id FROM Stocks)
	);

/* 25. Encontrar los nombres de productos que hayan sido vendidos por al menos dos tiendas distintas */
SELECT product_name
FROM   Products
WHERE

/* 26. Marcas que tengan productos de todas las categorías */

/* 27. Categorías que tengan productos de todas las marcas */

/* 28. Clientes que hayan realizado pedidos en todas las tiendas */
SELECT first_name, last_name FROM customers WHERE NOT EXISTS(
    (SELECT store_id FROM stores)
        MINUS
    (SELECT store_id FROM orders WHERE orders.customer_id = customers.customer_id)
);

/* 29. Tiendas (id y nombre) que hayan vendido todos los productos de la marca Strider */

/* 30. Tiendas que hayan vendido productos de todas las categorías */
SELECT store_id, store_name
FROM   Stores
WHERE  NOT EXISTS (
	(SELECT category_id FROM categories)
		MINUS
	(SELECT category_id FROM products,order_items,orders
		WHERE order_items.product_id = products.product_id
		AND   order_items.order_id   = orders.order_id
		AND   orders.store_id        = stores.store_id
	)
);

/* 31. Tiendas que hayan vendido productos de todas las marcas */
SELECT store_id, store_name FROM stores WHERE NOT EXISTS(
    SELECT * from brands WHERE NOT EXISTS(
        SELECT * from orders, order_items, products WHERE
            orders.order_id= order_items.order_id AND
            order_items.product_id = products.product_id AND

            orders.store_id = stores.store_id AND
            products.brand_id=brands.brand_id
    )
);

/* 32. Categorías que hayan sido vendidas por todas las tiendas */
