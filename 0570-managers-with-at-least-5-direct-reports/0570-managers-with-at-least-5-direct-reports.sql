# Write your MySQL query statement below

#Group by managerId having Count(*) >= 5
Select name
FROM Employee
WHERE id IN (Select managerId 
FROM Employee 
WHERE managerId IS NOT NULL
GROUP BY managerId
HAVING COUNT(*) >= 5);