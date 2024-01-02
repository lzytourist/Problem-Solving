SELECT 
    stds.student_id,
    stds.student_name,
    sub.subject_name,
    (CASE
        WHEN exm.subject_name IS NULL THEN 0
        ELSE COUNT(*)
    END) AS attended_exams
FROM
    Students stds
        JOIN
    Subjects sub
        LEFT JOIN
    Examinations exm ON stds.student_id = exm.student_id
        AND sub.subject_name = exm.subject_name
GROUP BY stds.student_id , sub.subject_name
ORDER BY stds.student_id , sub.subject_name;
