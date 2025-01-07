# Write your MySQL query statement below
SELECT s.product_id, s.year AS first_year, s.quantity, s.price
FROM Sales s
JOIN (
  SELECT product_id, MIN(year) AS year 
  FROM sales 
  GROUP BY product_id
  ) p
ON s.product_id = p.product_id
AND s.year = p.year

-- OR
-- WITH first_year_sales AS (
--   SELECT s.product_id, MIN(s.year) as first_year
--   FROM Sales s
--   INNER JOIN Product p
--   ON s.product_id = p.product_id
--   GROUP BY s.product_id)
-- SELECT f.product_id, f.first_year, s.quantity, s.price
-- FROM first_year_sales f
-- JOIN Sales s 
-- ON f.product_id = s.product_id
-- AND f.first_year = s.year