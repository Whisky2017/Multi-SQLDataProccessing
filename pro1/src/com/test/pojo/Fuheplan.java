package com.test.pojo;

import javax.persistence.Basic;
import javax.persistence.Column;
import javax.persistence.Entity;
import javax.persistence.Id;
import java.sql.Timestamp;

/**
 * Created by 世康 on 2016/9/27.
 */
@Entity
public class Fuheplan {

    public static final String FIELD_PLANID = "ID";
    public static final String FIELD_PLANVALUE = "值";
    public static final String FIELD_PLANTIME = "时间";
    public static final String FIELD_PLANSORTID = "类型ID";

    private int planId;
    private String planValue;
    private Timestamp planTime;
    private Integer planSortId;

    @Id
    @Column(name = "planId", nullable = false)
    public int getPlanId() {
        return planId;
    }

    public void setPlanId(int planId) {
        this.planId = planId;
    }

    @Basic
    @Column(name = "planValue", nullable = true, length = 255)
    public String getPlanValue() {
        return planValue;
    }

    public void setPlanValue(String planValue) {
        this.planValue = planValue;
    }

    @Basic
    @Column(name = "planTime", nullable = true)
    public Timestamp getPlanTime() {
        return planTime;
    }

    public void setPlanTime(Timestamp planTime) {
        this.planTime = planTime;
    }

    @Basic
    @Column(name = "planSortId", nullable = true)
    public Integer getPlanSortId() {
        return planSortId;
    }

    public void setPlanSortId(Integer planSortId) {
        this.planSortId = planSortId;
    }

    @Override
    public boolean equals(Object o) {
        if (this == o) return true;
        if (o == null || getClass() != o.getClass()) return false;

        Fuheplan fuheplan = (Fuheplan) o;

        if (planId != fuheplan.planId) return false;
        if (planValue != null ? !planValue.equals(fuheplan.planValue) : fuheplan.planValue != null) return false;
        if (planTime != null ? !planTime.equals(fuheplan.planTime) : fuheplan.planTime != null) return false;
        if (planSortId != null ? !planSortId.equals(fuheplan.planSortId) : fuheplan.planSortId != null) return false;

        return true;
    }

    @Override
    public int hashCode() {
        int result = planId;
        result = 31 * result + (planValue != null ? planValue.hashCode() : 0);
        result = 31 * result + (planTime != null ? planTime.hashCode() : 0);
        result = 31 * result + (planSortId != null ? planSortId.hashCode() : 0);
        return result;
    }
}
