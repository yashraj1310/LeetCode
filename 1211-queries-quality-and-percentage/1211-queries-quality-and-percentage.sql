# Write your MySQL query statement below

-- Duplicates
-- Rating < 3 -> poor query
-- query_name, quality, poor_query_percentage
-- GROUP BY query_name


SELECT q.query_name, 
ROUND(AVG(q.rating/q.position), 2) 
AS quality,
ROUND(AVG(CASE WHEN q.rating < 3 THEN 1.0 ELSE 0.0 END)*100.0, 2)
AS poor_query_percentage
FROM Queries q
GROUP BY q.query_name