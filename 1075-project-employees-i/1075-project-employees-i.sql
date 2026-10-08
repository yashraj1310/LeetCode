# Write your MySQL query statement below

-- 1)Avg experience years of all employees
-- 2) Group By project

SELECT p.project_id, ROUND(AVG(experience_years), 2) AS average_years
FROM Project p
LEFT JOIN Employee e
ON p.employee_id = e.employee_id
GROUP BY p.project_id