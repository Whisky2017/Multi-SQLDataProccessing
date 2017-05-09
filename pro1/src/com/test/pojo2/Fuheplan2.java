package com.test.pojo2;

import javax.persistence.Basic;
import javax.persistence.Column;
import javax.persistence.Entity;
import javax.persistence.Id;
import java.sql.Timestamp;

/**
 * Created by 世康 on 2016/9/27.
 */
@Entity
public class Fuheplan2 {

    public static final String FIELD_PLANID = "ID 2";
    public static final String FIELD_PLANVALUE = "值 2";
    public static final String FIELD_PLANTIME = "时间 2";
    public static final String FIELD_PLANSORTID = "类型ID 2";

    private int planId2;
    private String planValue2;
    private Timestamp planTime2;
    private Integer planSortId2;

    @Id
    @Column(name = "planId", nullable = false)
    public int getPlanId2() {
        return planId2;
    }

    public void setPlanId2(int planId) {
        this.planId2 = planId;
    }

    @Basic
    @Column(name = "planValue", nullable = true, length = 255)
    public String getPlanValue2() {
        return planValue2;
    }

    public void setPlanValue2(String planValue) {
        this.planValue2 = planValue;
    }

    @Basic
    @Column(name = "planTime", nullable = true)
    public Timestamp getPlanTime2() {
        return planTime2;
    }

    public void setPlanTime2(Timestamp planTime) {
        this.planTime2 = planTime;
    }

    @Basic
    @Column(name = "planSortId", nullable = true)
    public Integer getPlanSortId2() {
        return planSortId2;
    }

    public void setPlanSortId2(Integer planSortId) {
        this.planSortId2 = planSortId;
    }

    @Override
    public boolean equals(Object o) {
        if (this == o) return true;
        if (o == null || getClass() != o.getClass()) return false;

        Fuheplan2 fuheplan = (Fuheplan2) o;

        if (planId2 != fuheplan.planId2) return false;
        if (planValue2 != null ? !planValue2.equals(fuheplan.planValue2) : fuheplan.planValue2 != null) return false;
        if (planTime2 != null ? !planTime2.equals(fuheplan.planTime2) : fuheplan.planTime2 != null) return false;
        if (planSortId2 != null ? !planSortId2.equals(fuheplan.planSortId2) : fuheplan.planSortId2 != null) return false;

        return true;
    }

    @Override
    public int hashCode() {
        int result = planId2;
        result = 31 * result + (planValue2 != null ? planValue2.hashCode() : 0);
        result = 31 * result + (planTime2 != null ? planTime2.hashCode() : 0);
        result = 31 * result + (planSortId2 != null ? planSortId2.hashCode() : 0);
        return result;
    }
}
