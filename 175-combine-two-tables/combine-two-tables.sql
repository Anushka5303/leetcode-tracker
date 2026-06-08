# Write your MySQL query statement below
select P.firstname as firstName, P.lastname as lastName, A.city as city, A.state as 
state from Person P left join Address A
on
P.personId = A.personId;
