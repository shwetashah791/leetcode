# Write your MySQL query statement below
-- month, country, count(trans), total(amt), count(approved_trans), total(amt)
SELECT DATE_FORMAT(trans_date, '%Y-%m') month, country, 
        COUNT(state) trans_count, 
        SUM(IF(state = 'approved', 1, 0)) approved_count, 
        SUM(amount) trans_total_amount,
        SUM(IF(state = 'approved', amount, 0)) approved_total_amount
FROM Transactions
GROUP BY 1, 2

-- -- OR
-- SELECT DATE_FORMAT(trans_date, '%Y-%m') month, country, 
--         COUNT(state) trans_count, 
--         SUM(CASE WHEN state = 'approved' THEN 1 ELSE 0 END) approved_count, 
--         SUM(amount) trans_total_amount,
--         SUM(CASE WHEN state = 'approved' THEN amount ELSE 0 END) approved_total_amount
-- FROM Transactions
-- GROUP BY 1, 2