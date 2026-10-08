# Write your MySQL query statement below

-- GROUP BY country, month(trans_date)
-- Count
-- 1) COUNT(*)
-- 2) SUM(t.amount)
-- 3) SUM(CASE WHEN state = 'approved' THEN 1 ELSE 0 END)
-- 4) SUM(CASE WHEN state='approved' THEN t.amount ELSE 0 END)

SELECT DATE_FORMAT(t.trans_date, '%Y-%m') AS month,
t.country AS country,
COUNT(*) AS trans_count,
SUM(CASE WHEN state = 'approved' THEN 1 ELSE 0 END) AS approved_count,
SUM(t.amount) AS trans_total_amount,
SUM(CASE WHEN state='approved' THEN t.amount ELSE 0 END) AS approved_total_amount
FROM Transactions t
GROUP BY t.country, DATE_FORMAT(t.trans_date, '%Y-%m')