package com.test.service;

import com.test.pojo.Fuheplan;

import java.util.List;

/**
 * Created by 世康 on 2016/9/19.
 */
public interface FuheplanService {

    public List<Fuheplan> getFuheplanAll();

    public List<Fuheplan> getFuheplan(int currentPaging, int pageSize);

    public Fuheplan getFuheplanById(String id);

    public int getFuheplanCount();
}
