# Write your MySQL query statement below

-- delivery date = order date --> immediate 
-- otherwise --> scheduled
-- Only one first order
-- % of immediate orders in first orders of all customers

-- 1) MIN(t.order_date) - first order

SELECT ROUND(AVG(CASE WHEN d.order_date = d.customer_pref_delivery_date THEN 1.0 ELSE 0.0 END) * 100.0, 2)
AS immediate_percentage
FROM Delivery d
WHERE (d.customer_id, d.order_date) 
IN ( SELECT customer_id, MIN(order_date) FROM Delivery GROUP BY customer_id);