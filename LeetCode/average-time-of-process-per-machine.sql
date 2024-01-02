WITH ActivityCalc AS (
    SELECT 
        s.machine_id, SUM((e.timestamp - s.timestamp)) AS elapsed, count(*) AS total_process
    FROM
        Activity s
            LEFT JOIN
        Activity e ON s.machine_id = e.machine_id
            AND s.process_id = e.process_id
            AND e.activity_type = 'end'
    WHERE
        s.activity_type = 'start'
    GROUP BY s.machine_id
)
SELECT machine_id, CAST(elapsed / total_process AS DECIMAL(5, 3)) AS processing_time
from ActivityCalc;
