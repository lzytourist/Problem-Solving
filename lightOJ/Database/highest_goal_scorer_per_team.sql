WITH info AS
  (SELECT team,
          max(goals_scored) AS mx_g
   FROM Goals
   GROUP BY team)
SELECT player,
       Goals.team,
       Goals.goals_scored,
       played
FROM Goals
RIGHT JOIN info ON Goals.goals_scored = info.mx_g
AND Goals.team = info.team
ORDER BY Goals.team,
         Goals.player;
