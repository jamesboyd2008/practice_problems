{
    score=$4;
    if (score >= 90)
    {
        grade="A";
    }
    else if (score >= 80)
    {
        grade="B";
    }
    else if (score >= 70)
    {
        grade="C";
    }
    else if (score >= 60)
    {
        grade="D";
    }
    else
    {
        grade="F";
    }

    FS = "|";
    if ($2~name)
    {
        print $3, $4, grade
    }
}
