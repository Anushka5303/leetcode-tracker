# Write your MySQL query statement below
select(
select salary  from Employee
where salary < (select max(salary) from employee)
order by salary desc
limit 1
)as SecondHighestSalary;