SELECT item,
       LAST_DAY(last_d) AS date,
       COUNT
FROM
  (SELECT item,
          YEAR(`date`) * 100 + MONTH(`date`) AS mon,
          MAX(`date`) AS last_d,
          sum(`count`) AS COUNT
   FROM product
   GROUP BY mon,
            item
   ORDER BY item) AS TMP ;
